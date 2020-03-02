/* C++ program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>

using namespace std;

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* tworzymy tymczasowe tablice */
    int L[n1], R[n2]; 
  
    /* kopiuj dane do tymczasowych tablic L[] i R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* połącz ponownie tablice tymczasowe arr[l..r]*/
    i = 0; // Początkowy indeks pierwszej podtablicy
    j = 0; // Początkowy indeks drugiej podtablicy 
    k = l; // Początkowy indeks zmergowanej(połączonej) podtablicy 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Skopiuj pozostałe elementy L [], jeśli takie istnieją */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Skopiuj pozostałe elementy R [], jeśli takie istnieją */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l oznacza lewy indeks, a r jest prawym indeksem pod-tablicy arr do sortowania */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Tak samo jak (l + r) / 2, ale unika przepełnienia 
        int m = l+(r-l)/2; 
  
        // rekrencyjne wywołanie, dopóki l<r
        mergeSort(arr, l, m); //sortowanie 1 połówki
        mergeSort(arr, m+1, r);   //sortowanie 2 połówki
  
        merge(arr, l, m, r); //złączenie dwóch połówek posortowanych , w dwóch poprzednich krokach
    } 
} 
  
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << A[i] << " " ; 
} 
  
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Podana tablica: ";
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "\nPosortowana (zmergowana) tablica \n"; 
    printArray(arr, arr_size); 
    return 0; 
}