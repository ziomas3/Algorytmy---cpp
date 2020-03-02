#include <iostream>

struct node
{
    int x;
    node *left;
    node *right;

    node(int x0, node* l=NULL, node* r=NULL)
        :x(x0), left(l), right(r)
    {}
};


void insert(node *& t, int x) //wstawianie
{
    node **t1=&t;
    while(*t1){
        if(x < (*t1)->x)
            t1 = &((*t1)->left);
        else
            t1 = &((*t1)->right);
    }
    *t1 = new node(x);
}
//procedura insert działa na drzewie o wysokości/głębokości h w czasie O(h) 


node* find(node * t, int x)  //wyszukiwanie klucza
{
    while(t && t->x != x)
    {
        if(x < t->x)
            t = t->left;
        else 
            t = t->right;
    }
    return t;
}
//procedura find działa na drzewie o wysokości/głębokości h w czasie O(h) 


void remove(node * &t, int x) //usuwanie elementu z drzewa
{
    node **t1=&t;
    while(*t1 && (*t1)->x != x)
    {
        if(x < (*t1)->x)
            t1 = &((*t1)->left);
        else
            t1 = &((*t1)->right);
    }

    if (*t1)
    {
        if((*t1)->right && (*t1)->left)
        {
            node **t2 = &((*t1)->right);
            while ((*t2)->left)
                t2 = &((*t2)->left);
            (*t1)->x = (*t2)->x;
            t1 = t2;
        }
        if((*t1)->left==NULL)
        {
            node *d = (*t1)->right;
            delete *t1;
            (*t1) = d;
        }
        else
        {
            node *d = (*t1)->left;
            delete *t1;
            (*t1)=d;
        }
    }    
}
//procedura remove działa na drzewie o wysokości/głębokości h w czasie O(h) 




int main()
{
	node* t=NULL; // tworzymy puste drzewo BST
	
	// dodajemy klucze

	insert(t,3);
	insert(t,4); 
	insert(t,1);
	insert(t,7);
	insert(t,-4);
	insert(t,9);
	insert(t,2);
	
	std::cout << "wyszukaj 9: " << find(t,9)->x << std::endl;
	std::cout << "usuń korzeń (" << t->x << "): " ;
    remove(t,t->x); 
    std::cout << std::endl;	 
	std::cout << "usuń 9: " ;
    remove(t,9);  
}
