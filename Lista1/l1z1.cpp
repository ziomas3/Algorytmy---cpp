#include <iostream>
int potega(int x,int n)
{
    if (n==0) return 1;
    if (n==1) return x;
    if (n%2==0)
    {
        int pot=potega(x,n/2);
        return pot*pot;
    }
    else 
    {
        int pot=potega(x,n/2);
        return x*pot*pot;
    }
}
int main()
{
    std::cout << potega(2,3) << std::endl;
    return 0;
}