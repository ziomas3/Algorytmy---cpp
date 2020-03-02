#include<iostream>
using namespace std;

/*
Algorytm jest oparty na tym samym pomy�le, co algorytm sortowania QuickSort. Dla danej tablicy A[1..n] oraz liczby k, algorytm wybiera element
dziel�cy m (np. pierwszy element z tablicy), a nast�pnie u�ywa go do podzielenia
tablicy na dwie cz�ci. Do pierwszej cz�ci tablicy - A[1..r] - zostaj� przeniesione elementy o warto�ciach mniejszych lub r�wnych m.
Do drugiej cz�ci (A[r+1..n]) - elementy o warto�ciach wi�kszych lub r�wnych m. Poniewa� naszym zadaniem jest jedynie wyznaczenie k-tego
co do wielko�ci elementu tablicy, mo�emy zamiast 2 wywo�a� rekurencyjnych (jak to by�o w przypadku algorytmu QuickSort) wykona� tylko jedno
wywo�anie rekurencyjne. Je�li k<= r, to poszukiwana warto�� znajduje si� w pierwszej cz�ci tablicy, wpp. mo�emy
zaw�zi� poszukiwania do drugiej cz�ci tablicy, jednak zamiast wyszukiwa� k-tej warto�ci musimy poszukiwa� (k-r)-tej warto�ci.


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
 Niestety, w pesymistycznym przypadku ten algorytm mo�e zachowywa� si� bardzo �le. Dla uporz�dkowanego ci�gu i k=n czas dzia�ania algorytmu wynosi O(n^2).
Jednak tak jak w przypadku algorytmu QuickSort, w �redni koszt dzia�ania algorytmu jest znacznie lepszy i wynosi O(n). */



inline int partition (int t[], int n)
{
  int k = -1;
  double x = t[n / 2]; // pivot bierzemy posrodku
  for(;;)
  {
     while (t[--n] > x);
     while (t[++k] < x);
     if (k < n) std::swap(t[k],t[n]);
     else       return k;
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
