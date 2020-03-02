#include <iostream>
#include <random>
struct BSTnode  // drzewo bez wskaźnika na rodzica
{ 
    int x;
    BSTnode* left;
    BSTnode* right;
    
    BSTnode(int x0, BSTnode* l=NULL, BSTnode* r=NULL)
    :x(x0), left(l), right(r)
    {}
};

void insert_recursive(BSTnode *& t, int x) // wstawianie (rekurenycjnie)
{
    if(!t)
        t=new BSTnode(x);
    else
        if(x<t->x)
            insert_recursive(t->left,x); // tail recursion
        else
            insert_recursive(t->right,x); // tail recursion
}

void inorder(BSTnode *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorder(t->left);
        std::cout<<t->x<<" ";
        inorder(t->right);
    }
}
int poziom(BSTnode *t, int klucz)
{
    BSTnode *n = t;
    int level = 1;
    while (n && n->x != klucz)
    {
        level++;
        if (klucz < n->x)
            n = n->left;
        else n = n->right;
    }
    return n ? level : 0;
}
int main()
{
    BSTnode *root = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{1,100};
    int liczba = 0;
    int los = generate(gen);
    for (auto i=0; i<1; i++)
    {
        int r = generate(gen);
        if (i == los/10)
            liczba = r;
        insert_recursive(root, r);
        std::cout << r << " ";
    }
    std::cout << "\nZADANIE 7:";
    std::cout << "\nLiczba: " << liczba << " Poziom: " << poziom(root, liczba) << std::endl;
    return 0;
}