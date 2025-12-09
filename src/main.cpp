/**
 * @file main.cpp
 * @brief Prosty program demonstrujacy dzialanie szablonowej klasy MergeSort.
 */

#include <iostream>
#include "MergeSort.h"

 /**
  * @brief Wypisuje wszystkie elementy tablicy na standardowe wyjscie.
  *
  * Elementy sa wypisywane w jednym wierszu, oddzielone pojedyncza spacja.
  *
  * @tparam T typ elementow przechowywanych w tablicy
  * @param array wskaznik na pierwszy element tablicy
  * @param size liczba elementow w tablicy
  */
template <typename T>
void printArray(const T* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

/**
 * @brief Glowna funkcja programu demonstrujacego sortowanie.
 *
 * Tworzy przykladowe tablice typu int oraz double, wypisuje ich
 * zawartosc przed sortowaniem, nastepnie sortuje je za pomoca
 * MergeSort<T>::sort i ponownie wypisuje posortowane wyniki.
 *
 * @return Kod wyjscia programu (0 oznacza poprawne zakonczenie).
 */
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
