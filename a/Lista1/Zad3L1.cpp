#include <iostream>

double oblicz(double a[], int n, double x)
{
    double wynik = a[0];
    for(int i = 0; i<=n; i++)
        wynik = wynik*x + a[i];
    return wynik;
}

int main()
{
    double a[] = {0.0, 1.0, 3.0, 5.0, 9.0, 11.0, 16.0};
    int a_rozmiar = sizeof(a)/sizeof(a[0]);
    std::cout << "Aby wyliczyć wartość wielomianu stopnia " << a_rozmiar << ", potrzeba " << oblicz(a, a_rozmiar, 3) << " mnożeń" << std::endl;


}