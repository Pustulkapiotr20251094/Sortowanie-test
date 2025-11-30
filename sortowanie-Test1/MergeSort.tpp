// Definicje metod szablonu MergeSort

template <typename T>
void MergeSort<T>::sort(T* array, int size)
{
    if (size <= 1)
        return;

    mergeSort(array, 0, size - 1);
}

template <typename T>
void MergeSort<T>::mergeSort(T* array, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
}

template <typename T>
void MergeSort<T>::merge(T* array, int left, int mid, int right)
{
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    T* leftArray = new T[sizeLeft];
    T* rightArray = new T[sizeRight];

    // Kopiowanie lewej czêœci
    for (int i = 0; i < sizeLeft; ++i)
        leftArray[i] = array[left + i];

    // Kopiowanie prawej czêœci
    for (int j = 0; j < sizeRight; ++j)
        rightArray[j] = array[mid + 1 + j];

    int i = 0;        // indeks w leftArray
    int j = 0;        // indeks w rightArray
    int k = left;     // indeks w tablicy wynikowej 'array'

    // Scalanie dwóch posortowanych czêœci
    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            ++i;
        }
        else
        {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Kopiowanie pozosta³ych elementów z lewej tablicy (jeœli s¹)
    while (i < sizeLeft)
    {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Kopiowanie pozosta³ych elementów z prawej tablicy (jeœli s¹)
    while (j < sizeRight)
    {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }

    delete[] leftArray;
    delete[] rightArray;
}
