#include <iostream>


struct node {
    int value;
    node *next;
    
    node(int x, node *n = nullptr)
    :value(x), next(n)
    {}
};

struct Node  // drzewo bez wskaźnika na rodzica
{ 
    int x;
    Node* left;
    Node* right;
    
    Node(int x0, Node* l=NULL, Node* r=NULL)
    :x(x0), left(l), right(r)
    {}
};

int find_level(Node *root, double v)
{
    Node *n = root;
    int level = 1;
    while (n && n->x != v)
    {
        level++;
        if (v < n->x)
            n = n->left;
        else n = n->right;
    }
    return n ? level : 0;
}

void zadanie7()
{
    Node *root = nullptr;
    
    }
    std::cout << "\nZADANIE 7:";
    std::cout << "\nLiczba: " << liczba << " Poziom: " << find_level(root, liczba) << std::endl;
}