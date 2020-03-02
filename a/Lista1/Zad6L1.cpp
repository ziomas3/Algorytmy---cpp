#include <iostream>

double szukaj(double a[], int n)
{
    int liczba = n;
    double max=0;
    double min=0;

    if (liczba%2!=0) 
    {
        liczba-=1;
        max=a[liczba];
        min=a[liczba];
    }
    int licznik=0;
    for(int i=0; i<liczba;i+=2)
    {
        if (a[i] > a[i+1])
            {
                if (max==0) max=a[i];
                if (min==0) min=a[i+1];
                if (a[i] > max) max=a[i];
                if (a[i+1] < min) min=a[i+1];
                licznik+=3;
            }
            else
            {
                if (max==0) max=a[i+1];
                if (min==0) min=a[i];
                if (a[i+1] > max) max=a[i+1];
                if (a[i] < min) min=a[i];
                licznik+=3;
            }
            
    }

    std::cout << "ilość porównań: " << licznik << std::endl;
    std::cout << "max: " << max <<std::endl << "min: " << min  << std::endl;
    return true;
}

int main()
{
    double a[7] = {3.,1.,12.,52.,45.,11.,102.};
    int rozmiar = sizeof(a)/sizeof(a[0]);
    szukaj(a, rozmiar);

    std::cout << "Liczba porównań nie może przekroczyć 3n/2 porównań, czyli: " << 3*rozmiar/2 << std::endl;

    return 0;
}