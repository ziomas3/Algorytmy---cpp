#include <iostream>
#include <cmath>

double P(int k, int n, double p)
{
    double sum = 0.;
    double q = 1.-p;
    double w = pow(q,n);
    for(int i=1; i<=k; i++)
    {
        sum += w;
        w *= (n-1)/i * p/q;
    }
    return sum;
}

int main()
{
    int n = 10;
    int k = 4; 
    double p = 0.5; 
    std::cout << P(k, n, p) << std::endl;
}