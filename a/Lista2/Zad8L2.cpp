#include <iostream>
#include <random>


void zadanie8()
{
    nodeBST *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        insertBST(L, i);
        std::cout << r << " ";
    }
    std::cout << "\nWysokość to: " << hBST(L) << std::endl;
}