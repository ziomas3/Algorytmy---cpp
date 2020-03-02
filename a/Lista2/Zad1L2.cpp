#include <iostream>

//wyszukiwanie binarne
int szukaj(int x, int n, int t[])
{
    int poczatek = 0 ;
    int koniec = n-1;

    int licznik = 0;

    while(poczatek<=koniec)
    {
        licznik++;
        int srodek = (poczatek+koniec)/2;

        if (x == t[srodek])
            {
                licznik++;
                std::cout << "Znalazłeś szukana liczbę: " << x << " w " << licznik << " porownaniach" << std::endl;
                break;
            }
        else if (x < t[srodek])
            {
                licznik++;
                koniec = srodek - 1;
            }
        else
            poczatek = srodek + 1;
    }
return 0;
}

int main()
{
    int x = 18;
    int n = 13;

    int t[n] = {10,12,13,14,18,20,25,27,30,35,40,45,47};
    szukaj(x,n,t);

    return 0;
}
