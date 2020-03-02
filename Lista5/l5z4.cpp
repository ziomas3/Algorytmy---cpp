
// C++ implementation of Radix Sort :)
#include<iostream>
using namespace std;

int getMax(int tab[], int n)
{
    int maximum = tab[0];
    for (int i = 1; i < n; i++)
        if (tab[i] > maximum)
            maximum = tab[i];
    return maximum;
}

void countingSort(int tab[], int n, int exp)
{
    int output[n]; //to będzie nasz output
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (tab[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (tab[i]/exp)%10 ] - 1] = tab[i];
        count[ (tab[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        tab[i] = output[i];
}

void radixsort(int tab[], int n)
{
    int m = getMax(tab, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(tab, n, exp);
}

// Wypisanie tablicy
void print(int tab[], int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
}

int main()
{
    int tab[] = {1,34,123,321,432,132,543,651,91,32,987,910,643,641,12,342,498,987,965,122,121,431,350};
    int n = sizeof(tab)/sizeof(tab[0]);
    radixsort(tab, n);
    print(tab, n);
    return 0;
}



