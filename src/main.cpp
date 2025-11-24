#include <iostream>
#include "MergeSort.h"

int main()
{
    // Tablica z liczbami int
    int tabInt[] = { 5, 2, 9, 1, 5, 6 };
    int sizeInt = sizeof(tabInt) / sizeof(tabInt[0]);

    // Tablica z liczbami double
    double tabDouble[] = { 3.14, -2.71, 0.0, 1.41, 2.71, 21.37, -987 };
    int sizeDouble = sizeof(tabDouble) / sizeof(tabDouble[0]);

    std::cout << "Przed sortowaniem (int): ";
    for (int i = 0; i < sizeInt; ++i)
    {
        std::cout << tabInt[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Przed sortowaniem (double): ";
    for (int i = 0; i < sizeDouble; ++i)
    {
        std::cout << tabDouble[i] << " ";
    }
    std::cout << "\n";

    // Wywo³anie naszej klasy szablonowej
    MergeSort<int>::sort(tabInt, sizeInt);
    MergeSort<double>::sort(tabDouble, sizeDouble);

    std::cout << "Po sortowaniu (int): ";
    for (int i = 0; i < sizeInt; ++i)
    {
        std::cout << tabInt[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Po sortowaniu (double): ";
    for (int i = 0; i < sizeDouble; ++i)
    {
        std::cout << tabDouble[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
