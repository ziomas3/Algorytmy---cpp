#include <iostream>
#include <random>


struct lnode  
{
    int x;
    lnode* next;
    
    lnode(int x0=0, lnode* n=nullptr)
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


lnode* merge (lnode *L1, lnode *L2)
{
    if (!L1)
    {
        return L2;
    }
    else if (!L2)
    {
        return L1;
    }
    if (L1->x < L2->x)
    {
        L1->next = merge(L1->next, L2);
        return L1;
    }
    else
    {
        L2->next = merge(L1, L2->next);
        return L2;
    }
}
void MergeSort(lnode **L)
{
	lnode *first = nullptr;
	lnode *second = nullptr;
	lnode *temp = nullptr;
	first = *L;
	temp = *L;
 
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		// znajdowanie polowy listy
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				temp = temp->next;
				first = first->next; //first idzie po liscie 2x szybciej niz temp, wiec temp bedzie w polowie listy
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *L;
	}
 
	// dzielenie listy na 2
	MergeSort(&first);
	MergeSort(&second);
 
     
	*L = merge(first, second);
}

int main()
{
    lnode *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
        insert(L, generate(gen));
    std::cout << "\nPrzed:\n";
    inorder(L);
    MergeSort(&L);
    std::cout << "\nPo:\n";
    inorder(L);
    return 0;
}