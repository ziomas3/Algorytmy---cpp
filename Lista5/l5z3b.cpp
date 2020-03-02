#include <iostream>
#include <vector>
#include <string>

std::vector< std::vector<int> > counting_sort(int t[], int n, int c)
{
    std::vector<std::vector<int>> a = {{},{},{},{},{},{},{},{},{},{}};
    std::string tempe;
for (int i = 0; i<n;i++)
{
    tempe=std::to_string(t[i]);
    std::cout<< (int)tempe[tempe.length()-1-c];
    int b = (int)tempe[tempe.length()-1-c]-48;
    if (tempe[tempe.length()-1-c] || tempe[tempe.length()-1-c]=='-'); else b=0;
    a[b].push_back(t[i]);
}
    return a;
}

int main()
{
    const int N = 5;
    int arr[N] = {30, 9, -8, -11, 6};
    
     std::vector<std::vector<int>> a=counting_sort(arr, N, 1);
    
    for (int i = 0; i<10; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j<a[i].size(); j++)
        {
            std::cout << a[i][j] << " ";
        }
        
    }
    return 0;
}

