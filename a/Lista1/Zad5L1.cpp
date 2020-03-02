#include <iostream>
#include <cmath>

struct lnode{
  int key;
  lnode *next;
};

int nty(int n, lnode *l)
{
  int ostatni=1;
  if (n==ostatni)
    return l->key;
  else
    nty(n-1,l->next);
  return 0;
}

int main()
{
  lnode* p;
std::cout<<nty(3,p);
}