#include<iostream>
#include<cstdlib>
#include <fstream>
 
int main()
{
        std::fstream tekst("Zad9.txt");
        char litera;
        int licznik = 0;
        
        while(tekst >> litera) 
        {
                ++licznik; 
        }
        std::cout << "Plik zawiera: " << licznik << " znaków. " << std::endl;
        char *zawartosc_pliku = new char[licznik]; 
        int zlicz[123] = {}; 
        tekst.close();
        tekst.clear();
        tekst.open("Zad9.txt");
        licznik=0;
        while(tekst >> litera) 
        {
                zawartosc_pliku[licznik]=litera;
                ++licznik; 
        }
        
        int i=0; 
        
        while(zawartosc_pliku[i])
        {
                ++zlicz[zawartosc_pliku[i]]; 
                ++i;
        }
        
        for(int i=97;i<123;i++)
                        std::cout<<(char)i<<" - "<<zlicz[i]<<std::endl;
                        
        for(int i=65;i<91;i++) 
                        std::cout<<(char)i<<" - "<<zlicz[i]<<std::endl;   
        
        
        return 0;
}