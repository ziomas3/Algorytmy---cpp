#include <iostream>
#include <random>

struct lnode
{
    int key;
    lnode *next;
    lnode(int x, lnode *n = nullptr)
    :key(x), next(n)
    {}
};
void insert(lnode *& t, int x) // wstawianie (nierekurencyjna)
{
    lnode **t1=&t;
    while(*t1)
        t1 = &((*t1)->next);
    *t1=new lnode(x);
}

void print_list(lnode *t) //rekurencyjnie
{
    if(t)
    {
        std::cout << t->key << " ";
        print_list(t->next);
    }
}

lnode insertion_sort (lnode *L)
{
    if(!L || !L->next)
        return *L;
    lnode *sorted = nullptr;
    while (L)
    {
        lnode *head = L;
        lnode **trail = &sorted;
        L = L->next;
        while (!(*trail == nullptr || head->key < (*trail)->key))
            trail = &(*trail)->next;
        head->next = *trail;
        *trail = head;
        print_list(sorted);
        std::cout << std::endl;
    }
    return *sorted;
}

int main()
{
    lnode *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        insert(L, generate(gen));
    }
    std::cout << "\nPrzed:\n";
    print_list(L);
    lnode L_after = insertion_sort(L);
    std::cout << "\nPo:\n";
    print_list(&L_after);
	return 0;
}