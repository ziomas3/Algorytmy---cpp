#include <iostream>
#include <fstream>
#include <string>

int *mnowiel(int A[], int B[], int m, int n, int &o) 
{ 
   int *c = new int[m+n-1]; 
    o=m+n-1;
   for (int i = 0; i<m+n-1; i++) 
     c[i] = 0; 
  
   for (int i=0; i<m; i++) 
   { 
     for (int j=0; j<n; j++) 
     {
         c[i+j] += A[i]*B[j]; 
     }
   } 

   return c; 
} 

int main()
{
    int m = 0;
    int n = 0; 
    int o = 0;

    std::ifstream inFilea("a.txt");
    int i=0;
    if (inFilea.is_open())
    {
        std::string line;
        
        while( std::getline(inFilea, line, ',') )
        {
            i++;
            m++;
        }
    }
    int *A = new int[i];
    inFilea.close();
    inFilea.clear();
    inFilea.open("a.txt");
    if (inFilea.is_open())
    {
        std::string line;
        i=0;
        while( std::getline(inFilea, line, ',') )
        {
            A[i]=std::stoi(line);
            i++;
        }
    }
    inFilea.close();
    std::ifstream inFileb("b.txt");
    i=0;
    if (inFileb.is_open())
    {
        std::string line;
        
        while( std::getline(inFileb, line, ',') )
        {
            i++;
            n++;
        }
    }
    int *B = new int[i];
    inFileb.close();
    inFileb.clear();
    inFileb.open("a.txt");
    if (inFileb.is_open())
    {
        std::string line;
        i=0;
        while( std::getline(inFileb, line, ',') )
        {
            B[i]=std::stoi(line);
            i++;
        }
    }
    inFileb.close();
    
    
    
    int *C =mnowiel(A, B, m, n, o); 
    
    
    std::ofstream zapis("c.txt");
	for(int j=0;j<o;j++)
	zapis<<C[j]<<",";
	
	zapis.close(); 
	return 0;
    return 0;
}