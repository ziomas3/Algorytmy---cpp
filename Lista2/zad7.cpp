#include <iostream>

int licznik=0;

struct nodeBST  // drzewo bez wskaźnika na rodzica
{
    int x;
    nodeBST* left;
    nodeBST* right;
    
    nodeBST(int x0, nodeBST* l=NULL, nodeBST* r=NULL)
    :x(x0), left(l), right(r)
    {}
};

void insertBST(nodeBST *& t, int x) // wstawianie 
{
    nodeBST **t1=&t;
    while(*t1)
        if(x < (*t1)->x)
        {
            t1=&((*t1)->left);
            licznik++;
        }
        else
        {
            t1=&((*t1)->right);
            licznik++;
        }
    *t1=new nodeBST(x);
}

int hBST(nodeBST* t) // wysokość drzwa BST 
{
    return !t ? 0 : 1+std::max(hBST(t->left),hBST(t->right));
}

void displayBST(nodeBST *t,char z1=' ',char z2=' ') // in order z nawiasami
{
    if(t)
    {
        std::cout<<z1;
        displayBST(t->left,'(',')');
        std::cout<<t->x;
        displayBST(t->right,'[',']');
        std::cout<<z2;
    }
}

void inorderBST(nodeBST *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorderBST(t->left);
        std::cout<<t->x<<" ";
        inorderBST(t->right);
    }
}

void zadanie7(int n)
{
    nodeBST *N = nullptr;
    for (auto i=1; i<=n; i++)
    {
        insertBST(N, i);
    }
    displayBST(N);
    std::cout << "\nGłębokość drzewa: " << hBST(N) << std::endl;
    std::cout << "Ilość porównań: " << licznik << std::endl;
}


int main()
{
    zadanie7(8);
    return 0;
}