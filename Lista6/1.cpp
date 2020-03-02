#include <iostream>
#include <string>
#include <cmath>

//wyszukiwanie binarne
int h(std::string s)
{
    int len=s.length();
    int wynik=0;
    for (int i=0;i<len;i++)
    {
        wynik+=int(s[i]);
    }
    return wynik%50;

}

int main()
{
    std::cout << h("konski przysmak") << std::endl << h("ala");

    return 0;
}
