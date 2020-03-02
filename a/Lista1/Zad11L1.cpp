#include <iostream>
#include <cmath>

int sito_erastotenesa(int n)
{
    bool prime[n];

    for(int k=1; k<n; k++)
        prime[k]=true;

    for(int k=2; k<=sqrt(n); k++)
    {
        if (prime[k] == true)
        {
            for(int w=k*k; w<=n; w+=k)
                prime[w] = false;
        }
    }

    std::cout << "Liczby pierwsze mniejsze od " << n << " to: "; 
    for (int k=2; k<=n; k++)
    {
        if (prime[k]==true)
            std::cout << k << " ";
    }
    return 0;
}


int main()
{
    int n=11;
    sito_erastotenesa(n);
}