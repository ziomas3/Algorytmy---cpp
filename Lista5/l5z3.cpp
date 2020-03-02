#include <iostream>
#include <vector>
#include <string>

std::vector< std::vector<int> > counting_sort(int t[], int n, int c)
{
    std::vector<std::vector<int>> a = {{},{},{},{},{},{},{},{},{},{}};
    std::string temp;
for (int i =0; i<n;i++)
{
    if (c==0) c=-1;
    temp=std::to_string(t[i]);
    int j=0;
    for (j; j<temp.length();j++)
    {
        if(temp[j] == ',')
        {
            j=j+c;
        a[int(j)].push_back(t[i]);
        }
    }
}
    return a;
}

int main()
{
    const int N = 5;
    int arr[N] = {3, 9, -8, -11, 6};
    
     std::vector<std::vector<int>> a=counting_sort(arr, N, 0);
    
    
    
    
    for (int i = 0; i<10; i++)
    {
        for (int j = 0; j<a[i].size(); j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

