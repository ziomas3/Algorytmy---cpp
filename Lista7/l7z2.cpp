#include <iostream>
#include <string>
#include <cmath>

//wyszukiwanie binarne
int f(int n)
{
    int licznik=0;
    int a=0;
    while(n)
    {
    a=log2(n);
    licznik++;
    n-=pow(2,a);
    }
    return licznik;

}

int main()
{
    std::cout << f(24) << std::endl;

    return 0;
}