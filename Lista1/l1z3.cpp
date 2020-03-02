#include <iostream>
double oblicz (double a[],int n, double x)
{
    double sum=0; double ix=1;
    for(int i =0;  i<=n; i++)
    {
        sum+=a[i]*ix;
        ix*=x;
    }
    return sum;
}
double oblicz2 (double a[],int n, double x)
{
    double s=a[0];
    for (int i=0; i<n;i++)
    {
        s=(s+a[i])*x;
    }
    return s;
}
int main()
{
    double s[4]={2.,2.,3.,5.};
    std::cout << oblicz(s,3,10.) << std::endl;
    std::cout << oblicz2(s,3,10.) << std::endl;
    return 0;
}