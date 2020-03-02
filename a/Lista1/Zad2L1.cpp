#include <iostream>
#include <cmath>

double f(double x)
{
    return sin(x-0.5);
}

double bisekcja(double a, double b)
{
    if (f(a)==0.0) return a;
    if (f(b)==0.0) return b;

    double s; //środek przedziału
    
    while (b-a >= 0.0000001)
    {
        s=(a+b)/2;
        if(f(s) == 0.0) //jesli m0 jest w środku
            return s;
        if(f(a)*f(s)<0)
            b=s;
        else 
            a=s; 
    }
    return (a+b)/2;
}

int main()
{
    double a=-3;
    double b=3;

    std::cout << "Pierwiastek funkcji f wynosi: " << bisekcja(a,b) << std::endl;

    return 0;
}