#include <iostream>
double mam(double a[],int se)
{
    int si = se;
    double max=0,min=0;
    if (si%2!=0) 
    {
        si-=1;
        max=a[si];
        min=a[si];
    }
    int licznik=0;
    for(int i=0; i<si;i+=2)
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

    std::cout << licznik << std::endl;
    std::cout << max <<std::endl << min;
    return true;
}
int main()
{
    double s[6]={2.,5.,8.,5.,7.,5.};
    int size=sizeof(s)/sizeof(s[0]);
    mam(s, size);
    return 0;
}