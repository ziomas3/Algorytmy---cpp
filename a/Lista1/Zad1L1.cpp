#include <iostream>


//wersja z użyciem rekurencji
int fr(int x, int n)
{
    if (n==0)
        return 1;
    if (n==1)
        return x;
    else if (n%2 != 0)
        return x*fr(x,n-1);
    int z = fr(x,n/2);
    return z*z;
}

//wersja bez użycia rekurencji -> iteracyjnie
int fi(int x, int n)
{
    int z = 1;
    while(n--)
        z *=x;
    return z;
}

int main()
{
    std::cout << fr(2,3) << std::endl;
    std::cout << fi(3,4) << std::endl;
}

