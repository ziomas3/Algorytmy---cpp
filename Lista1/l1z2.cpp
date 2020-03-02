#include <iostream>
double f(double x)
{
    return x-0.1;
}
double fu(double x)
{
    double popx,a,b;
    a=0;
    b=1;
    while(f(x)!=0)
    {
        popx=x;
        x=(a+b)/2;
        if(popx==x)
            return 1;
        if (f(x)==0)
            return x;
        else 
            if(f(x)>0)
                b=x;
            else 
                a=x;
    }
}
int main()
{
    std::cout << f(2.45) << std::endl;
    return 0;
}