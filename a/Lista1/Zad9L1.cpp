#include <iostream>
#include <fstream>

int main()
{
        std::fstream tekst("Zad9.txt");
        char litera;
        int licznik = 0;
        
        while(tekst >> litera) 
                ++licznik; 

        std::cout << "Plik zawiera: " << licznik << " znaków. " << std::endl;
        std::cout << "Liczba wystapień poszczególnych liter: " << std::endl;
        tekst.close();
        tekst.clear();
        tekst.open("Zad9.txt");

        char *t = new char[litera]; //tablica, która przechowuje tekst z pliku
        int zliczanie[123] = {}; //123 bo tyle liter w ascii
        licznik = 0;
        while(tekst >> litera)
        { 
                t[licznik]=litera;
                ++licznik; 
        }
        int i=0;

        while(t[i])
        {
                ++zliczanie[t[i]];
                ++i;
        }

        for(int i=97; i<123; i++) //małe litery ascii
                        std::cout << (char)i << " - " << zliczanie[i] << std::endl;

                
        for(int i=65; i<91; i++) //duże litery ascii
                        std::cout << (char)i << " - " << zliczanie[i] << std::endl;
        
        return 0;
}

