#include <iostream>
#include "MergeSort.h"

template <typename T>
void printArray(const T* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int main()
{
    int tabInt[] = { 5, 2, 9, 1, 5, 6 };
    double tabDouble[] = { 3.14, -2.71, 0.0, 1.41, 2.71, 21.37, -987.0 };

    int sizeInt = sizeof(tabInt) / sizeof(tabInt[0]);
    int sizeDouble = sizeof(tabDouble) / sizeof(tabDouble[0]);

    std::cout << "Przed sortowaniem (int): ";
    printArray(tabInt, sizeInt);

    std::cout << "Przed sortowaniem (double): ";
    printArray(tabDouble, sizeDouble);

    MergeSort<int>::sort(tabInt, sizeInt);
    MergeSort<double>::sort(tabDouble, sizeDouble);

    std::cout << "Po sortowaniu (int): ";
    printArray(tabInt, sizeInt);

    std::cout << "Po sortowaniu (double): ";
    printArray(tabDouble, sizeDouble);

    return 0;
}
