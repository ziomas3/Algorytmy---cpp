#include <iostream>
#include <cmath>

double P(int k, int n, double p)
{
    double wynik = 0.;
    double q = 1.-p;
    double w = pow(q,n);  //dla i=0
    for(int i=1; i<=k; i++)
    {
        wynik += w;
        w *= (n-1)/(i+1) * p/q;
    }
    return wynik;
}

int main()
{
    int n = 10; //próby
    int k = 4; //sukcesy
    double p = 0.5; //prawdopodobieństwo
    std::cout << "Szansa na to, że w " << n << " próbach będzie nie więcej niż " << k << " sukcesów, wynosi: " << P(k, n, p) << std::endl;
}