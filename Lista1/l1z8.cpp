#include <iostream>

class ulamek {
    public:
        double licznik;      
        double mianownik;     
        
        void ogarnij() 
        {
            int b=mianownik;
            int a=licznik;
            if( a != b ) 
            {
                do 
                {
                    if( a > b ) 
                    {
                        a = a - b;
                    }
                    if( a < b ) 
                    {
                        b = b - a;
                    };
                }
                while( a != b );
        
            }
            licznik = licznik / a;
            mianownik = mianownik / a;
        }
        //+
        ulamek operator+(const ulamek& b) 
        {
            ulamek ul;
            if(this->mianownik == b.mianownik)
            {
                ul.licznik = this->licznik + b.licznik;
                ul.mianownik = this->mianownik;
            }
            else
            {
                ul.licznik = (this->licznik*b.mianownik) + (b.licznik*this->mianownik);
                ul.mianownik = this->mianownik * b.mianownik;
            }
            if (ul.licznik>0)
                ul.ogarnij();
            return ul;
        }
        //-
        ulamek operator-(const ulamek& b) 
        {
            ulamek ul;
            if(this->mianownik == b.mianownik)
            {
                ul.licznik = this->licznik - b.licznik;
                ul.mianownik = this->mianownik;
            }
            else
            {
                ul.licznik = (this->licznik*b.mianownik) - (b.licznik*this->mianownik);
                ul.mianownik = this->mianownik * b.mianownik;
            }
            if (ul.licznik>0)
                ul.ogarnij();
            return ul;
        }
        //*
        ulamek operator*(const ulamek& b) 
        {
            ulamek ul;
            ul.licznik = this->licznik * b.licznik;
            ul.mianownik = this->mianownik * b.mianownik;
            if (ul.licznik>0)
                ul.ogarnij();
            return ul;
        }
        // /
        ulamek operator/(const ulamek& b) 
        {
            ulamek ul;
            ul.licznik = this->licznik * b.mianownik;
            ul.mianownik = this->mianownik * b.licznik;
            if (ul.licznik>0)
                ul.ogarnij();
            return ul;
        }
        ulamek(int a, int b =1)
        {licznik = a;   mianownik = b; }
        ulamek()
        {licznik = 0;   mianownik = 1;}
        friend std::ostream & operator << (std::ostream &out, const ulamek &c);
        friend std::istream & operator >> (std::istream &in,  ulamek &c);
    
};
std::ostream & operator << (std::ostream &out, const ulamek &c)
{
    out << c.licznik<< "/" << c.mianownik << std::endl;
    return out;
}
 
std::istream & operator >> (std::istream &in,  ulamek &c)
{
    std::cout << "Licznik: ";
    in >> c.licznik;
    std::cout << "Mianownik: ";
    in >> c.mianownik;
    return in;
}

int main()
{
    ulamek u1(1,5);
    ulamek u2(2,3);
    std::cout << u1 << u2;
    std::cout << u1+u2;
    std::cout << u1-u2;
    std::cout << u1*u2;
    std::cout << u1/u2;
    return 0;
}