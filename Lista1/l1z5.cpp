#include <iostream>

struct lnode
{
    int key;
    lnode *next;
};

int nty(int n, lnode *l)
{
    if(!l) return 0;
    int i = 0;  
    if(i == n) 
    return l->key; 
    if (l->next==NULL) return 0;
    return nty(n-1, l->next);  
}

int main()
{
    return 0;
}