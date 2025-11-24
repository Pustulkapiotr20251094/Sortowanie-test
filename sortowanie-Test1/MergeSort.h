#ifndef MERGESORT_H
#define MERGESORT_H

// Szablon klasy MergeSort
template <typename T>
class MergeSort
{
public:
    // Funkcja publiczna - wywo³ujemy j¹ z main
    static void sort(T* array, int size)
    {
        if (size <= 1)
            return; // tablica pusta lub 1 element - ju¿ posortowana

        mergeSort(array, 0, size - 1);
    }

private:
    // Rekurencyjne dzielenie tablicy na pó³
    static void mergeSort(T* array, int left, int right)
    {
        if (left >= right)
            return; // fragment ma 0 lub 1 element

        int mid = (left + right) / 2;

        // Sortujemy lew¹ po³owê
        mergeSort(array, left, mid);

        // Sortujemy praw¹ po³owê
        mergeSort(array, mid + 1, right);

        // Scalanie dwóch posortowanych po³ówek
        merge(array, left, mid, right);
    }

    // Scalanie dwóch posortowanych czêœci tablicy
    static void merge(T* array, int left, int mid, int right)
    {
        int sizeLeft = mid - left + 1;
        int sizeRight = right - mid;

        // Tworzymy tymczasowe tablice
        T* leftArray = new T[sizeLeft];
        T* rightArray = new T[sizeRight];

        // kopiujemy dane do tymczasowych tablic
        for (int i = 0; i < sizeLeft; ++i)
        {
            leftArray[i] = array[left + i];
        }

        for (int j = 0; j < sizeRight; ++j)
        {
            rightArray[j] = array[mid + 1 + j];
        }

        // Indeksy do przechodzenia po tablicach
        int i = 0;        // lewa tablica
        int j = 0;        // prawa tablica
        int k = left;     // pozycja w tablicy g³ównej

        // Scala dwie posortowane tablice w jedn¹
        while (i < sizeLeft && j < sizeRight)
        {
            if (leftArray[i] <= rightArray[j])
            {
                array[k] = leftArray[i];
                i++;
            }
            else
            {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        // Jeœli coœ zosta³o w lewej tablicy
        while (i < sizeLeft)
        {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        // Jeœli coœ zosta³o w prawej tablicy
        while (j < sizeRight)
        {
            array[k] = rightArray[j];
            j++;
            k++;
        }

        // Sprz¹tanie – zwalniamy pamiêæ
        delete[] leftArray;
        delete[] rightArray;
    }
};

#endif // MERGESORT_H
