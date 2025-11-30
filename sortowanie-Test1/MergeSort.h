/// Klasa realizuj¹ca sortowanie przez scalanie (MergeSort) jako szablon.
/// Obs³uguje typy takie jak int, long, double, float itp.
template <typename T>
class MergeSort
{
public:
    /// Sortuje tablicê 'array' o d³ugoœci 'size' rosn¹co.
    static void sort(T* array, int size);

private:
    static void mergeSort(T* array, int left, int right);
    static void merge(T* array, int left, int mid, int right);
};

// Do³¹czamy plik z definicjami szablonu
#include "MergeSort.tpp"
