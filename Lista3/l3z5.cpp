#include <iostream>


void merge (int start, int mid, int end, int arr[], int *t)
{
    int i,j,q;
    //pasting data to temp table
    for (i=start; i<=end; i++)
        t[i] = arr[i];
    i = start;
    j = mid + 1;
    q = start;
    //pasting data from temp table to original table with sorting them out
    while (i<= mid && j<= end)
    {
        if(t[i] < t[j])
            arr[q++] = t[i++];
        else
            arr[q++] = t[j++];
    }
    //If j came to end, and i isn't in mid yet
    while (i <= mid)
        arr[q++] = t[i++];
}

void mergesort(int start, int end, int arr[])
{
    int *t = new int[end + 1];
    int mid;
    if(start < end)
    {
        mid = (start + end)/2;
        //left side
        mergesort(start, mid, arr);
        //right side
        mergesort(mid+1, end, arr);
        //merging both
        merge(start, mid, end, arr, t);
    }
    delete[] t;
}

int main()
{
    const int N = 5;
    int arr[N] = {3, 9, -8, -11, 6};
    
    mergesort(0, N - 1, arr);
    
    
    puts("Marge Sort Na Tablicy");
    
    for (int i = 0; i<N; i++)
        std::cout << arr[i] << ", ";
    return 0;
}

