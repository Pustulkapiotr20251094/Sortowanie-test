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
TEST(MergeSortIntTests, SortsNegativeArrayWithDuplicates)
{
    int arr[] = { -5, -1, -5, -3, -1, -7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy int zawierajacej liczby ujemne,
 *       dodatnie oraz duplikaty.
 */
TEST(MergeSortIntTests, SortsMixedWithDuplicates)
{
    int arr[] = { -5, 0, 3, -5, 2, 0, -1, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza, czy algorytm zachowuje dwuelementowa tablice int,
 *       ktora jest juz posortowana rosnaco.
 */
TEST(MergeSortIntTests, KeepsTwoElementsSorted)
{
    int arr[] = { 1, 2 };
    int size = 2;

    MergeSort<int>::sort(arr, size);

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
}

/**
 * @test Sprawdza sortowanie duzej tablicy int (150 elementow),
 *       poczatkowo posortowanej malejaco.
 */
TEST(MergeSortIntTests, SortsLargeArray)
{
    const int N = 150;
    int arr[N];

    // Tablica od N do 1 (odwrotnie posortowana)
    for (int i = 0; i < N; ++i)
        arr[i] = N - i;

    MergeSort<int>::sort(arr, N);

    expectSortedAscending(arr, N);
}

/**
 * @test Sprawdza sortowanie duzej tablicy int (200 elementow)
 *       z wartosciami ujemnymi, dodatnimi oraz duplikatami.
 */
TEST(MergeSortIntTests, SortsLargeArrayWithNegativesAndDuplicates)
{
    const int N = 200;
    int arr[N];

    for (int i = 0; i < N; ++i)
    {
        int v = (i % 20) - 10; // -10 .. 9 (ujemne, dodatnie, duplikaty)
        arr[i] = v;
    }

    MergeSort<int>::sort(arr, N);

    expectSortedAscending(arr, N);
}

//
// ===== TESTY DLA double =====
//  (te same przypadki co wyzej, ale dla typu double)
//

/**
 * @test Sprawdza, czy algorytm zachowuje tablice double,
 *       gdy jest ona juz posortowana rosnaco.
 */
TEST(MergeSortDoubleTests, KeepsAlreadySortedArray)
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    double expected[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    for (int i = 0; i < size; ++i)
        EXPECT_EQ(expected[i], arr[i]);
}

/**
 * @test Sprawdza sortowanie tablicy double, ktora jest posortowana
 *       w odwrotnej kolejnosci (malejaco).
 */
TEST(MergeSortDoubleTests, SortsReversedArray)
{
    double arr[] = { 5.0, 4.0, 3.0, 2.0, 1.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie losowej tablicy double.
 */
TEST(MergeSortDoubleTests, SortsRandomArray)
{
    double arr[] = { 10.0, -3.0, 7.0, 0.0, 5.0, -1.0, 8.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy double zawierajacej
 *       tylko liczby ujemne.
 */
TEST(MergeSortDoubleTests, SortsOnlyNegativeNumbers)
{
    double arr[] = { -5.0, -10.0, -3.0, -1.0, -7.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy double zawierajacej liczby
 *       ujemne i dodatnie.
 */
TEST(MergeSortDoubleTests, SortsNegativeAndPositiveNumbers)
{
    double arr[] = { -5.0, 10.0, -3.0, 0.0, 7.0, -1.0, 2.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza obsluge pustej tablicy double (nullptr, rozmiar 0).
 */
TEST(MergeSortDoubleTests, HandlesEmptyArray)
{
    double* arr = nullptr;
    int size = 0;

    MergeSort<double>::sort(arr, size);
    SUCCEED();
}

/**
 * @test Sprawdza, czy algorytm nie zmienia tablicy double
 *       zawierajacej tylko jeden element.
 */
TEST(MergeSortDoubleTests, KeepsSingleElementArray)
{
    double arr[] = { 42.0 };
    int size = 1;

    MergeSort<double>::sort(arr, size);

    EXPECT_EQ(42.0, arr[0]);
}

/**
 * @test Sprawdza sortowanie tablicy double z duplikatami liczb.
 */
TEST(MergeSortDoubleTests, SortsArrayWithDuplicates)
{
    double arr[] = { 5.0, 1.0, 3.0, 5.0, 2.0, 1.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy double zawierajacej liczby ujemne
 *       z duplikatami.
 */
TEST(MergeSortDoubleTests, SortsNegativeArrayWithDuplicates)
{
    double arr[] = { -5.0, -1.0, -5.0, -3.0, -1.0, -7.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza sortowanie tablicy double z liczbami ujemnymi,
 *       dodatnimi oraz duplikatami.
 */
TEST(MergeSortDoubleTests, SortsMixedWithDuplicates)
{
    double arr[] = { -5.0, 0.0, 3.0, -5.0, 2.0, 0.0, -1.0, 3.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

/**
 * @test Sprawdza, czy algorytm zachowuje dwuelementowa tablice double,
 *       ktora jest juz posortowana rosnaco.
 */
TEST(MergeSortDoubleTests, KeepsTwoElementsSorted)
{
    double arr[] = { 1.0, 2.0 };
    int size = 2;

    MergeSort<double>::sort(arr, size);

    EXPECT_EQ(1.0, arr[0]);
    EXPECT_EQ(2.0, arr[1]);
}

/**
 * @test Sprawdza sortowanie duzej tablicy double (150 elementow),
 *       poczatkowo posortowanej malejaco.
 */
TEST(MergeSortDoubleTests, SortsLargeArray)
{
    const int N = 150;
    double arr[N];

    for (int i = 0; i < N; ++i)
        arr[i] = static_cast<double>(N - i);

    MergeSort<double>::sort(arr, N);

    expectSortedAscending(arr, N);
}

/**
 * @test Sprawdza sortowanie duzej tablicy double (200 elementow)
 *       z wartosciami od -10 do 9 (ujemne, dodatnie, duplikaty).
 */
TEST(MergeSortDoubleTests, SortsLargeArrayWithNegativesAndDuplicates)
{
    const int N = 200;
    double arr[N];

    for (int i = 0; i < N; ++i)
    {
        int v = (i % 20) - 10; // -10 .. 9
        arr[i] = static_cast<double>(v);
    }

    MergeSort<double>::sort(arr, N);

    expectSortedAscending(arr, N);
}
