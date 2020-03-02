#include <iostream>
#include <fstream>

int main()
{
    std::fstream plik_a;
    plik_a.open("a.txt", std::ios::in);

    std::fstream plik_b;
    plik_b.open("b.txt", std::ios::in);

    if(plik_a.good()==false || plik_b.good()==false)
        std::cout << "Nie ma takiego pliku!" << std::endl;

    char znak_a;   
    char znak_b;
    int nr_znaku = 0;

    std::cout << "wspolczynniki wielomianu a" << std::endl;
    while(plik_a.get(znak_a))
        std::cout << znak_a;
    
    


    std::cout << std::endl;
    std::cout << std::endl << "wspolczynniki wielomianu b" << std::endl;
    while(plik_b.get(znak_b))
        std::cout << znak_b;

    plik_a.close();
    plik_b.close();

    //std::fstream plik_c;
    //plik_c.open("c.txt", std::ios::out);
    //plik_c << wynik << std::endl;
    //plik_c.close();

    return 0;
}
