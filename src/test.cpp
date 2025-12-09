/**
 * @file test.cpp
 * @brief Zestaw testow jednostkowych dla szablonowej klasy MergeSort z wykorzystaniem Google Test.
 *
 * Plik zawiera testy dla dwoch typow danych: int oraz double.
 * Testy sprawdzaja rozne scenariusze: tablice posortowane, odwrotnie posortowane,
 * losowe dane, liczby ujemne, duplikaty oraz duze tablice.
 */

#include "pch.h"
#include "MergeSort.h"

 /**
  * @brief Pomocnicza funkcja sprawdzajaca, czy tablica jest posortowana rosnaco.
  *
  * Funkcja iteruje po elementach tablicy i sprawdza za pomoca EXPECT_LE,
  * czy kazdy kolejny element nie jest mniejszy od poprzedniego.
  * W razie bledu Google Test wygeneruje odpowiedni komunikat.
  *
  * @tparam T typ elementow w tablicy
  * @param array wskaznik na pierwszy element tablicy
  * @param size liczba elementow w tablicy
  */
template <typename T>
void expectSortedAscending(const T* array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        EXPECT_LE(array[i - 1], array[i])
            << "Tablica nie jest posortowana na pozycji " << i;
    }
}

//
// ===== TESTY DLA int =====
//

/**
 * @test Sprawdza, czy algorytm zachowuje tablice int,
 *       gdy jest ona juz posortowana rosnaco.
 */
TEST(MergeSortIntTests, KeepsAlreadySortedArray)
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    int expected[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < size; ++i)
        EXPECT_EQ(expected[i], arr[i]);
}

/**
 * @test Sprawdza sortowanie tablicy int, ktora jest posortowana
 *       w odwrotnej kolejnosci (malejaco).
 */
TEST(MergeSortIntTests, SortsReversedArray)
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie losowej tablicy int
 *       z wartosciami dodatnimi, ujemnymi i zerem.
 */
TEST(MergeSortIntTests, SortsRandomArray)
{
    int arr[] = { 10, -3, 7, 0, 5, -1, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza poprawne sortowanie tablicy int zawierajacej
 *       tylko liczby ujemne.
 */
TEST(MergeSortIntTests, SortsOnlyNegativeNumbers)
{
    int arr[] = { -5, -10, -3, -1, -7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy int zawierajacej
 *       liczby ujemne i dodatnie.
 */
TEST(MergeSortIntTests, SortsNegativeAndPositiveNumbers)
{
    int arr[] = { -5, 10, -3, 0, 7, -1, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza obsluge pustej tablicy int (wskaznik nullptr, rozmiar 0).
 *       Test weryfikuje, ze nie wystepuje wyjatek ani blad wykonania.
 */
TEST(MergeSortIntTests, HandlesEmptyArray)
{
    int* arr = nullptr;
    int size = 0;

    MergeSort<int>::sort(arr, size);
    SUCCEED(); // jesli doszlismy tutaj, to nie bylo bledu
}

/**
 * @test Sprawdza, czy algorytm nie zmienia tablicy int zawierajacej
 *       tylko jeden element.
 */
TEST(MergeSortIntTests, KeepsSingleElementArray)
{
    int arr[] = { 42 };
    int size = 1;

    MergeSort<int>::sort(arr, size);

    EXPECT_EQ(42, arr[0]);
}

/**
 * @test Sprawdza sortowanie tablicy int z duplikatami liczb.
 */
TEST(MergeSortIntTests, SortsArrayWithDuplicates)
{
    int arr[] = { 5, 1, 3, 5, 2, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy int zawierajacej liczby ujemne
 *       z duplikatami.
 */
TEST(Mer
