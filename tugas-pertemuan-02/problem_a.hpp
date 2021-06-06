#pragma once

#include <string>

/**
 * @brief Mengembalikan dua kali nilai dengan pointer.
 * @note
 * Misal:
 *    5 -> 10
 *    32 -> 64
 * @example
 *    int val1 = *multiply_by_two(5);
 *    // val1 == 10
 *    int val2 = *multiply_by_two(43);
 *    // val2 == 86
 *
 * @param n   bilangan bulat yang akan dimultiplikasi
 * @return    pointer yang merujuk ke n
 */
int *multiply_by_two(int &n);

/**
 * @brief Mengembalikan string dari karakter ke-3 dan ke-5 yang didapatkan dari pointer to array of char.
 * @note
 * Misal:
 *    "Maria" -> "ra"
 *    "Dstorv" -> "tr"
 * @example
 *    char str[] = "Velvid";
 *    std::string val = the_third_and_fifth(str);
 *    // val == "li"
 *
 * @param ptr pointer to array of char
 * @return    string yang diperoleh dari karakter ke-3 dan ke-5 dari array of char 
 */
std::string the_third_and_fifth(char *ptr);

/**
 * @brief Mencari panjang array of char dengan pointer.
 * @note
 * Misal:
 *    "Heart" -> 5
 * NOTE: JANGAN GUNAKAN FUNGSI strlen()
 * @example
 *    char str[] = "Wolf";
 *    int val = my_own_strlen(str);
 *    // val == 4
 *
 * @param   ptr pointer to array of char
 * @return  panjang array (integer)
 */
int my_own_strlen(char *ptr);

/**
 * @brief Menukar dua elemen pada array pada index ke-n menggunakan pointer.
 * @note
 * Misal:
 *    {1, 2, 3} | {4, 5, 6} | (2) -> {1, 2, 6} | {4, 5, 3}
 * @example
 *    int arr1[]{1, 2, 3};
 *    int arr2[]{4, 5, 6};
 *    element_swapper(arr1, arr2, 2);
 *    // arr1 == {1, 2, 6}
 *    // arr2 == {4, 5, 3}
 *
 * @param ptr1  pointer yang menunjuk ke array pertama
 * @param ptr2  pointer yang menunjuk ke array kedua
 * @param n     index elemen array yang akan ditukar
 */
void element_swapper(int *ptr1, int *ptr2, int n);
