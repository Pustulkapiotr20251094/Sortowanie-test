#include "pch.h"
#include "MergeSort.h"

// Pomocnicza funkcja: sprawdza czy tablica jest posortowana rosn¹co
template <typename T>
void expectSortedAscending(const T* array, int size)
{
    for (int i = 1; i < size; ++i)
    {
        EXPECT_LE(array[i - 1], array[i]) << "Tablica nie jest posortowana na pozycji " << i;
    }
}

//
// ===== TESTY DLA int =====
//

// 1. zachowuje tablicê niezmienion¹, gdy ona jest ju¿ posortowana rosn¹co
TEST(MergeSortIntTests, KeepsAlreadySortedArray)
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    int expected[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < size; ++i)
        EXPECT_EQ(expected[i], arr[i]);
}

// 2. potrafi posortowaæ tablicê, która jest posortowana w odwrotnej kolejnoœci
TEST(MergeSortIntTests, SortsReversedArray)
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 3. poprawnie sortuje losow¹ tablicê liczb
TEST(MergeSortIntTests, SortsRandomArray)
{
    int arr[] = { 10, -3, 7, 0, 5, -1, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 4. poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortIntTests, SortsOnlyNegativeNumbers)
{
    int arr[] = { -5, -10, -3, -1, -7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 5. poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortIntTests, SortsNegativeAndPositiveNumbers)
{
    int arr[] = { -5, 10, -3, 0, 7, -1, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 6. obs³uguje pust¹ tablicê bez rzucania wyj¹tkiem
TEST(MergeSortIntTests, HandlesEmptyArray)
{
    int* arr = nullptr;
    int size = 0;

    MergeSort<int>::sort(arr, size);
    SUCCEED();
}

// 7. nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortIntTests, KeepsSingleElementArray)
{
    int arr[] = { 42 };
    int size = 1;

    MergeSort<int>::sort(arr, size);

    EXPECT_EQ(42, arr[0]);
}

// 8. poprawnie sortuje tablicê z duplikatami liczb
TEST(MergeSortIntTests, SortsArrayWithDuplicates)
{
    int arr[] = { 5, 1, 3, 5, 2, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 9. poprawnie sortuje tablice ujemn¹ z duplikatami
TEST(MergeSortIntTests, SortsNegativeArrayWithDuplicates)
{
    int arr[] = { -5, -1, -5, -3, -1, -7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 10. poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortIntTests, SortsMixedWithDuplicates)
{
    int arr[] = { -5, 0, 3, -5, 2, 0, -1, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 11. poprawnie sortuje tablicê zawieraj¹c¹ tylko dwa elementy w kolejnoœci rosn¹cej
TEST(MergeSortIntTests, KeepsTwoElementsSorted)
{
    int arr[] = { 1, 2 };
    int size = 2;

    MergeSort<int>::sort(arr, size);

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
}

// 12. poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
TEST(MergeSortIntTests, SortsLargeArray)
{
    const int N = 150;
    int arr[N];

    for (int i = 0; i < N; ++i)
        arr[i] = N - i; // odwrotnie posortowana

    MergeSort<int>::sort(arr, N);

    expectSortedAscending(arr, N);
}

// 13. poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
// z liczbami ujemnymi, dodatnimi oraz duplikatami
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
//  (te same przypadki co wy¿ej, ale dla typu double)
//

// 1. zachowuje tablicê niezmienion¹, gdy ona jest ju¿ posortowana rosn¹co
TEST(MergeSortDoubleTests, KeepsAlreadySortedArray)
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    double expected[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    for (int i = 0; i < size; ++i)
        EXPECT_EQ(expected[i], arr[i]);
}

// 2. potrafi posortowaæ tablicê, która jest posortowana w odwrotnej kolejnoœci
TEST(MergeSortDoubleTests, SortsReversedArray)
{
    double arr[] = { 5.0, 4.0, 3.0, 2.0, 1.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 3. poprawnie sortuje losow¹ tablicê liczb
TEST(MergeSortDoubleTests, SortsRandomArray)
{
    double arr[] = { 10.0, -3.0, 7.0, 0.0, 5.0, -1.0, 8.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 4. poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortDoubleTests, SortsOnlyNegativeNumbers)
{
    double arr[] = { -5.0, -10.0, -3.0, -1.0, -7.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 5. poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortDoubleTests, SortsNegativeAndPositiveNumbers)
{
    double arr[] = { -5.0, 10.0, -3.0, 0.0, 7.0, -1.0, 2.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 6. obs³uguje pust¹ tablicê bez rzucania wyj¹tkiem
TEST(MergeSortDoubleTests, HandlesEmptyArray)
{
    double* arr = nullptr;
    int size = 0;

    MergeSort<double>::sort(arr, size);
    SUCCEED();
}

// 7. nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortDoubleTests, KeepsSingleElementArray)
{
    double arr[] = { 42.0 };
    int size = 1;

    MergeSort<double>::sort(arr, size);

    EXPECT_EQ(42.0, arr[0]);
}

// 8. poprawnie sortuje tablicê z duplikatami liczb
TEST(MergeSortDoubleTests, SortsArrayWithDuplicates)
{
    double arr[] = { 5.0, 1.0, 3.0, 5.0, 2.0, 1.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 9. poprawnie sortuje tablice ujemn¹ z duplikatami
TEST(MergeSortDoubleTests, SortsNegativeArrayWithDuplicates)
{
    double arr[] = { -5.0, -1.0, -5.0, -3.0, -1.0, -7.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 10. poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortDoubleTests, SortsMixedWithDuplicates)
{
    double arr[] = { -5.0, 0.0, 3.0, -5.0, 2.0, 0.0, -1.0, 3.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<double>::sort(arr, size);

    expectSortedAscending(arr, size);
}

// 11. poprawnie sortuje tablicê zawieraj¹c¹ tylko dwa elementy w kolejnoœci rosn¹cej
TEST(MergeSortDoubleTests, KeepsTwoElementsSorted)
{
    double arr[] = { 1.0, 2.0 };
    int size = 2;

    MergeSort<double>::sort(arr, size);

    EXPECT_EQ(1.0, arr[0]);
    EXPECT_EQ(2.0, arr[1]);
}

// 12. poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
TEST(MergeSortDoubleTests, SortsLargeArray)
{
    const int N = 150;
    double arr[N];

    for (int i = 0; i < N; ++i)
        arr[i] = static_cast<double>(N - i);

    MergeSort<double>::sort(arr, N);

    expectSortedAscending(arr, N);
}

// 13. poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
// z liczbami ujemnymi, dodatnimi oraz duplikatami
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
