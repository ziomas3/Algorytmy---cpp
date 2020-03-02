#include <iostream>

using namespace std;

void przesiej (double t[],int i, int n)
{
  int k;  // syn większy od ojca i brata
  double x = t[i]; //przesiewany element
  while(
        ( (k=2*i+2) < n && t[k] > x && t[k] > t[k-1] ) 
        || 
        (   --k < n && t[k] > x)
    )
    {
        t[i] = t[k];
        i  =   k;
    }
 
   t[i] = x;
}

void przesiej_w_gore (double t[],int i, double x)
{
  // początkowo x = t[i] 
  int k; // ojciec i 
  while( i && t[k=(i-1)/2] < x )
  {
       t[i] = t[k];
       i  =   k;
  }
  t[i] = x;
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


class heap
{
    double *t;
    int n;
    public:
    
    heap(double *t0, int n0=0):t(t0),n(n0)
    {
      int i=n/2; // budowa kopca 
      while(i) 
        przesiej (t, --i, n);
    }
    
    void insert(double x)
    {
        przesiej_w_gore(t,n++,x);
    }
    

    double max()
    {
        return t[0];
    }

    double get_max()
    {
        double res=t[0];
        t[0]=t[--n];
        przesiej(t,0,n);
        return res;
    }
    
};

void heap_sort_2 (double t[], int n)
{
  heap K(t,n);
  while(--n)
    t[n]=K.get_max();
}


int main()
{   double t[]={5,3,17,10,84,19,6,22,9};
    int n =sizeof(t)/sizeof(t[0]);
    heap_sort(t,n);
    for(double x :t)
        cout<<x<<' ';
}
