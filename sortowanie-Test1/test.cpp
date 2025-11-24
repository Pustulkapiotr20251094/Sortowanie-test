#include "pch.h"         // WA¯NE w projekcie Google Test w Visual Studio
#include "gtest/gtest.h"
#include "MergeSort.h"

// Pomocnicza funkcja – sprawdza, czy tablica jest posortowana rosn¹co
template <typename T>
bool isSorted(const T* array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (array[i - 1] > array[i])
            return false;
    }
    return true;
}

// Jeden prosty test: tablica ju¿ posortowana rosn¹co (int)
TEST(MergeSortArrayTest, AlreadySortedInt)
{
    int data[] = { 1, 2, 3, 4, 5 };
    int expected[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(data) / sizeof(data[0]);

    // Wywo³ujemy nasz MergeSort
    MergeSort<int>::sort(data, size);

    // Sprawdzamy, czy elementy s¹ takie, jak oczekiwane
    for (int i = 0; i < size; ++i)
    {
        EXPECT_EQ(data[i], expected[i]);
    }

    // Dodatkowo sprawdzamy, czy tablica jest posortowana
    EXPECT_TRUE(isSorted(data, size));
}