#pragma once

/**
 * @file MergeSort.h
 * @brief Deklaracja szablonowej klasy MergeSort implementujacej sortowanie przez scalanie.
 */

 /**
  * @brief Szablonowa klasa implementujaca algorytm sortowania przez scalanie.
  *
  * Klasa udostepnia statyczna funkcje sort(), ktora sortuje wskazana tablice
  * w kolejnosci rosnacej. Moze byc uzywana dla typow takich jak int, long,
  * double, float itp., pod warunkiem ze dostepny jest operator porownania <=.
  *
  * @tparam T typ elementow przechowywanych w tablicy
  */
template <typename T>
class MergeSort
{
public:
    /**
     * @brief Sortuje tablice w kolejnosci rosnacej algorytmem sortowania przez scalanie.
     *
     * Jesli wskaznik @p array jest rowny nullptr lub @p size jest mniejsze
     * lub rowne 1, funkcja nie wykonuje zadnych operacji.
     *
     * @param array wskaznik na pierwszy element tablicy do posortowania
     * @param size liczba elementow w tablicy
     */
    static void sort(T* array, int size);

private:
    /**
     * @brief Rekurencyjna funkcja pomocnicza wykonujaca sortowanie fragmentu tablicy.
     *
     * Funkcja sortuje podtablice z zakresu indeksow [left, right].
     *
     * @param array wskaznik na tablice z danymi
     * @param left indeks pierwszego elementu podtablicy
     * @param right indeks ostatniego elementu podtablicy
     */
    static void mergeSort(T* array, int left, int right);

    /**
     * @brief Scala dwa posortowane fragmenty tablicy w jeden posortowany zakres.
     *
     * Funkcja laczy zakresy [left, mid] oraz [mid + 1, right], zakladajac,
     * ze oba sa juz posortowane rosnaco.
     *
     * @param array wskaznik na tablice z danymi
     * @param left indeks pierwszego elementu lewej czesci
     * @param mid indeks ostatniego elementu lewej czesci
     * @param right indeks ostatniego elementu prawej czesci
     */
    static void merge(T* array, int left, int mid, int right);
};

/**
 * @brief Dolacza plik z definicjami metod szablonowych MergeSort.
 */
#include "MergeSort.tpp"
