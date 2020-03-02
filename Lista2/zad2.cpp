#include <iostream>

//a)
int maks_iteracyjnie(int t[], int n)
{
    int licznik = 0;
    int x = t[--n];

    while(n--){
        if(t[n]>x){
             x=t[n];   
        }
        licznik++;    
    }
    
    std::cout << "ITERACYJNIE liczba porównań: " << licznik << std::endl;

    return x;     
}

//b)
int maks_rekurencyjnie1(int t[], int n) 
{ 
    int licznik = 0;
    if (n == 1) 
        return t[0]; 
    //licznik++;
    //std::cout << "REKURENCYJNIE1 liczba porównań: " << licznik << std::endl;
    return std::max(t[n-1], maks_rekurencyjnie1(t, n-1)); 
    
} 

//c)
/*int maks_rekurencyjnie2(int t[], int n)
{
    int poczatek = 0;
    int koniec = n-1;
    int srodek = (poczatek+koniec)/2;
    
    return x;
}*/

int main()
{
    int t[10]={11,32,2,5,939,36,3,53,14,61};
    int n = sizeof(t)/sizeof(t[0]);

    //a) iteracyjnie
    std::cout << maks_iteracyjnie(t,n)  << std::endl;

    //b)rekurencyjnie n-1 
    std::cout <<  maks_rekurencyjnie1(t, n); 

    //c)rekurencyjnie podział na 2 tablice
    


    return 0;
    
    //a) iteracyjnie: n=9, wyszło 8 porównań -> ogólnie n-1 porównań 
}
