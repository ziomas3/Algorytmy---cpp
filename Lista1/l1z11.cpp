#include <iostream>
#include <cmath>

void sito_erastotenesa(int n)
{
    bool *prime= new bool[n];

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

    for (int k=2; k<=n; k++)
    {
        if (prime[k]==true)
            std::cout << k << " ";
    }
}


int main()
{
    int n=150;
    sito_erastotenesa(n);
}