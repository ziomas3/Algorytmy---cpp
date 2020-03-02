#include <iostream>


struct lnode  
{
    int x;
    lnode* next;
    
    lnode(int x0, lnode* n=nullptr)
    :x(x0), next(n)
    {}
};

void insert(lnode *& t, int x) // wstawianie 
{
    lnode **t1=&t;
    while(*t1)
        t1 = &((*t1)->next);
    *t1=new lnode(x);
}

void inorder(lnode *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorder(t->next);
        std::cout<<t->x<<" ";
    }
}

int licznik = 0;

lnode* merge (lnode *L1, lnode *L2)
{
    if (!L1)
    {
        licznik++;
        return L2;
    }
    else if (!L2)
    {
        licznik++;
        return L1;
    }
    if (L1->x < L2->x)
    {
        licznik++;
        L1->next = merge(L1->next, L2);
        return L1;
    }
    else
    {
        licznik++;
        L2->next = merge(L1, L2->next);
        return L2;
    }
}

void zadanie6()
{
    lnode *L1 = nullptr;
    lnode *L2 = nullptr;
    lnode *result = nullptr;
    for (auto i=0; i<10; i++)
    {
        insert(L1, i);
        insert(L2, i*3);
    }
    std::cout << "Lista 1: " << std::endl;
    inorder(L1);
    std::cout << "\nLista 2: " << std::endl;
    inorder(L2);
    result = merge(L1, L2);
    std::cout << "\n Złączone listy : " << std::endl;
    inorder(result);
    std::cout << "\nIlość porównań: " << licznik << std::endl;
}

int main()
{
    zadanie6();
    return 0;
}