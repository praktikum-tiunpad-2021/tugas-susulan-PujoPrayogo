#pragma once

#include <string>

/**
 * @brief Mengecek sebuah bilangan bulat apakah termasuk bilangan prima atau tidak.
 * @note
 * Misal:
 *    7 -> prima
 *    58 -> bukan prima
 *    101 -> prima
 * @example
 *    val1 = is_prime(101); // true
 *    val2 = is_prime(58);  // false
 *
 * @param n   bilangan bulat positif
 * @return    apakah bilangan prima atau tidak
 */
bool is_prime(int n);

/**
 * @brief Menghitung faktorial dari sebuah bilangan bulat positif.
 * @note
 * Misal:
 *    2! == 2 * 1 == 2
 *    4! == 4 * 3 * 2 * 1 == 24
 * @example
 *    val = factorial(4);
 *    // val == 24
 *
 * @param n   bilangan bulat positif
 * @return    faktorial dari `n`
 */
unsigned int factorial(unsigned int n);

/**
 * @brief Melakukan sort pada integer array secara ascending dan in-place.
 * @note
 * Misal:
 *    5, 2, 3, 1 -> 1, 2, 3, 5
 * @example
 *    arr = {5, 2, 3, 1};
 *    inplace_sort(4, arr)
 *    // val == {1, 2, 3, 5}
 *
 * @param n   ukuran array
 * @param arr array yang akan di-sort
 */
void inplace_sort(size_t n, int arr[]);

/**
 * @brief Membalik sebuah string secara in-place.
 * @note
 * Misal:
 *    "John Doe" -> "eoD nhoJ"
 *    "1234" -> "4321"
 * @example
 *    std::string s1 = "1234";
 *    inplace_reverse_str(s1);
 *    // s1 == "4321"
 *
 * @param str   string yang akan dibalik secara in-place
 */
void inplace_reverse_str(std::string &str);

/**
 * @brief Membalik sebuah string.
 * @note
 * Misal:
 *    "John Doe" -> "eoD nhoJ"
 *    "1234" -> "4321"
 * @example
 *    std::string s1 = "1234";
 *    std::string s2 = reverse_str(s1);
 *    // s2 == "4321"
 *
 * @param str   string yang akan dibalik
 * @return      hasil pembalikan string
 */
std::string reverse_str(const std::string &str);