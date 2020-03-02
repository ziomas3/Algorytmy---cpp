#include<iostream>
using namespace std;

/*
Algorytm jest oparty na tym samym pomyœle, co algorytm sortowania QuickSort. Dla danej tablicy A[1..n] oraz liczby k, algorytm wybiera element
dziel¹cy m (np. pierwszy element z tablicy), a nastêpnie u¿ywa go do podzielenia
tablicy na dwie czêœci. Do pierwszej czêœci tablicy - A[1..r] - zostaj¹ przeniesione elementy o wartoœciach mniejszych lub równych m.
Do drugiej czêœci (A[r+1..n]) - elementy o wartoœciach wiêkszych lub równych m. Poniewa¿ naszym zadaniem jest jedynie wyznaczenie k-tego
co do wielkoœci elementu tablicy, mo¿emy zamiast 2 wywo³añ rekurencyjnych (jak to by³o w przypadku algorytmu QuickSort) wykonaæ tylko jedno
wywo³anie rekurencyjne. Jeœli k<= r, to poszukiwana wartoœæ znajduje siê w pierwszej czêœci tablicy, wpp. mo¿emy
zawêziæ poszukiwania do drugiej czêœci tablicy, jednak zamiast wyszukiwaæ k-tej wartoœci musimy poszukiwaæ (k-r)-tej wartoœci.


  function AlgHoara(A[1..n],k);
  begin
   if n=1 and k=1 then return A[1];
   // Partition
   m:=A[1]; l:=1; r:=n;
   while(l<r) do begin
     while (A[l]<m) do l++;
     while (m<A[r]) do r--;
     if (l<=r) then begin
      tmp:=A[l]; A[l]:=A[r]; A[r]:=tmp;
      l++; r--;
    end;
  end;
  if (k<=r) then
    return AlgHoara(A[1..r],k)
  else
    return AlgHoara(A[r+1..n],k-r)
 end;
 Niestety, w pesymistycznym przypadku ten algorytm mo¿e zachowywaæ siê bardzo Ÿle. Dla uporz¹dkowanego ci¹gu i k=n czas dzia³ania algorytmu wynosi O(n^2).
Jednak tak jak w przypadku algorytmu QuickSort, w œredni koszt dzia³ania algorytmu jest znacznie lepszy i wynosi O(n). */



inline int partition (int t[], int n)
{
  int k = -1;
  int ile = n;
  double x = t[n / 2];
  while (true)
    {
      while (t[--n] > x);
      while (t[++k] < x);
      if (n > k)
      {
          double y = t[k];
        t[k] = t[n];
        t[n] = y;
      }
      else
	    return k;
    }
}

int kty(int t[], int n, int k)
{
    if(n == 1 && k == 1)
        return t[0];

    int p = partition(t, n);
    if(p >= k)
        return kty(t, p, k);
    else
        return kty(t+p, n-p,  k-p);
}

int main()
{
    int a[] = {5, 7, 3, 1};
    const int n = sizeof(a)/sizeof(a[0]);
    std::cout << kty(a, n, 1) << std::endl;
    std::cout << kty(a, n, 2) << std::endl;
    std::cout << kty(a, n, 3) << std::endl;
    std::cout << kty(a, n, 4) << std::endl;
}
