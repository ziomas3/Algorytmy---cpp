#include <iostream>

using namespace std;


/* Struktura 
(max min) - wezel  
          (0 1)
        /       \
   (2 3)         (4 5) 
  /    \        /    \
(6 7) (8 9) (10 11) (12 13) 

max-L 2*I+2
max-P 2*I+4
min-L 2*I+1
min-p 2*I+3
sąsiad min = max+1 
sąsiad max = min-1
*/

void przesiej_w_gore (double t[],int i, double x)
{
  int k; 
  if(i%2==0)
      while( i && t[k=(i-1)/4*2] < x )
      {
           t[i] = t[k];
           i  =   k;
      }
  else
      while( i>1 && t[k=i/4*2+1] > x )
      {
           t[i] = t[k];
           i  =   k;
      }
  t[i] = x;
}

void przesiej (double t[],int i, int n)
{
  int k;  
  double x = t[i]; 
  if(i%2==0) 
      while(
            ( (k=2*i+4) < n && t[k] > x && t[k] > t[k-2] ) 
            || 
            (   (k-=2) < n && t[k] > x)
        )
        {
            t[i] = t[k];
            i  =   k;
        }
   else 
       while(
            ( (k=2*i+3) < n && t[k] < x && t[k] < t[k-2] ) 
            || 
            (   (k-=2) < n && t[k] < x)
        )
        {
            t[i] = t[k];
            i  =   k;
        }
   t[i] = x;
   if(i%2==0) 
   {
       if(((k=i+1)<n && t[k]>x) || t[k=(i-1)/4*2+1]>x)
       {
          t[i]=t[k]; 
          przesiej_w_gore(t,k,x);
       }
   }
   else
   {
       if(t[i-1]<x)
       {
          t[i]=t[i-1]; 
          przesiej_w_gore(t,i-1,x);
       }       
   }
}

void heap_sort (double t[], int n)
{
  // Budowanie stogu  
  int i=n/2; // pierwszy element bez dzieci
  while(i) 
    przesiej (t, --i, n);
  // Opróżnianie stogu
  while(--n)
    {
      double x = t[n]; t[n] = t[0]; t[0] = x; // Zamień t[0] z t[n]
      przesiej (t, 0, n);
    }
}


class heap_min_max
{
    double *t;
    int n;
    public:
    
    heap_min_max(double *t0, int n0=0):t(t0),n(n0)
    {
      //~ int i=n/2; 
      //~ while(i) 
        //~ przesiej (t, --i, n);
    }
    
    void insert(double x)
    {
           int i=n++;
           int k;
           if(i%2==0) 
           {
               if(((k=i+1)<n && t[k]>x) || t[k=(i-1)/4*2+1]>x)
               {
                  t[i]=t[k]; 
                  przesiej_w_gore(t,k,x);
               }
               else
                  przesiej_w_gore(t,i,x);
           }
           else
           {
               if(t[i-1]<x)
               {
                  t[i]=t[i-1]; 
                  przesiej_w_gore(t,i-1,x);
               }       
               else
                  przesiej_w_gore(t,i,x);
           }

    }
    

    double max()
    {
        return t[0];
    }

    double min()
    {
         return t[n>1];        
    }

    double get_max()
    {
        double res=t[0];
        t[0]=t[--n];
        przesiej(t,0,n);
        return res;
    }

    double get_min()
    {
        if(n==1) 
            return t[--n];
        double res=t[1];
        t[1]=t[--n];
        przesiej(t,1,n);
        return res;
    }
    
    bool empty()
    {
        return n==0;
    }
};


int main()
{   double t[]={32,5,6,7,645,34,54,23,3,32,1231,43,24,26,62,7,4,5};
//    int n =sizeof(t)/sizeof(t[0]);
    
    
    heap_min_max K(new double[1000],0);
    heap_min_max L(new double[1000],0);
    
    for(double x :t)
    {
        cout<<x<<' ';
        K.insert(x);
        L.insert(x);
        cout<<K.min()<<":"<<K.max()<<endl;
    }
    
    while(not K.empty())
       cout<<K.get_max()<<" "; 
    cout<<endl;   
    
    while(not L.empty())
       cout<<L.get_min()<<" "; 
    cout<<endl;   
}
