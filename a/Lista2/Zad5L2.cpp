#include <iostream>


struct lnode  // drzewo bez wskaźnika na rodzica
{
    int x;
    lnode* next; //wskaźnik na kolejny element
    
    lnode(int x0, lnode* n=nullptr) //x0 klucz, i  domyślny wsakźnik na nic, ale można potem podać
    :x(x0), next(n) //konstruktor x=x0 i next = n
    {}
};

void insert(lnode *& t, int x) // wstawianie 
{
    lnode **t1=&t; //wskaźnik na wskaźnik - tworzymy wskźnik na wskaźnik o nazwie t1 wskazujący na lnode i zapisujemy do niego adres zmiennej t (wskaźnik wskazuje na miejsce w pamięci)
    while(*t1) //dopóki wskazuje na cokolwiek (t1)
        t1 = &((*t1)->next); //składowa o nazwie next obiektu wskazywanego przez wskaźnik o nazwie t1
    *t1=new lnode(x); //nowe drzewo
}

void inorder(lnode *t)  // wypisanie kluczy w porządku "in order" , żeby kolejne wartości były rosnąco
{
    if(t)
    {
        inorder(t->next);
        std::cout<<t->x<<" ";
    }
}

void reverse(lnode *&L) //
{
    lnode *previous = NULL;  
    lnode *next = NULL;
    while (L)
    {
        next = L->next; // składowa o nazwie next obiektu wskazywanego przez wskaźnik o nazwie L (current)
        L->next = previous;
        previous = L;
        L = next;
    }
    L = previous; //L(current) jest poprzednim
}


void zadanie5()
{
    lnode * t = nullptr;
    for (auto i=0; i<10; i++)
        insert(t, i);
    
    std::cout << "w porządku in-order: " << std::endl;
    inorder(t);
    std::cout << std::endl;
    std::cout << "Odwrócona lista L: " << std:: endl;
    reverse(t);
    inorder(t);
}

int main()
{
    zadanie5();
    return 0;
}