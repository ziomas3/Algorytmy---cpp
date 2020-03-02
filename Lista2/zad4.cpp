#include <iostream>
#include <cmath>

#define N 2

double iloczynSkalarny(double a[],double b[],int n)
{
    double iloczyn=0;
    for(int i=0;i<n;i++)
        iloczyn+=a[i]*b[i]; 
    return iloczyn;
} //n mnożeń

double wielomian(double w[],double x,int n)
{
    double wielomian=0;
    for(int i=0;i<n;i++)
        wielomian = wielomian*x + w[i];
    return wielomian; 
} // n - mnożeń

double iloczynWielomianow(double w1[],double w2[],int n)
{
    double w3[2*n-1]; //2*n bo w1 i w2 mają ten sam stopień n
    for(int i=0;i<2*n-1;i++)
        w3[i]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            w3[i+j] += w1[i]*w2[j]; 
    }
    return w3[2*n-1];
} //n^2 (każdy z każdym)

int iloczynMacierzy(int m1[][N], int m2[][N], int m3[][N])
{
    int i, j, k;

    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            m3[i][j]=0;
            for(k=0;k<N;k++)
                m3[i][j] += m1[i][k]*m2[k][j];
        }
    }
} //n^3 mnozen

double wyznacznik(int n, double m[4][4])
{
    double d = 0;
    double temp[4][4];
    if (n == 2)
        return ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));
    else
    {
        for (int k = 0; k < n; k++)
        {
            int xi = 0;
            for (int i = 1; i < n; i++)
            {
                int xj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == k)
                        continue;    

                    temp[xi][xj] = m[i][j];
                    xj++;

                }
                xj++;
            }

            d = d + (pow(-1, k) * m[0][k] * wyznacznik(n - 1, temp)); 
        }
    }

    return d;
} //4*(n-1)


int main() 
{ 
    int i, j; 
    int m3[N][N]; 
    int m1[N][N] = {{1, 2}, {3, 4}};
  
    int m2[N][N] = {{2, 1}, {1, 2}};  
  
    iloczynMacierzy(m1, m2, m3);
  
    std::cout << "Iloczyn macierzy wynosi: \n"; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        std::cout << m3[i][j] << " "; 
        std::cout << "\n"; 
    } 
  
//wyznacznik
    int n = 4;
    double m[n][n] = {{1,2,4,5},{1,2,4,3},{1,2,0,3},{1,1,3,6}};
    std::cout << "\n wyznacznik macierzy m wynosi: " << wyznacznik(n,m);

    return 0; 
} 