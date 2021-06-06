#pragma once

#include "shape.hpp"

/**
 * @brief Membuat Lingkaran dengan jari-jari tertentu
 *
 * @note
 * Misal:
 *    Jari-jari Lingkaran = 2.5
 *
 * @example
 *    Lingkaran l = {...};
 *    Lingkaran *l = new_lingkaran(2.5f);
 *    // Lingkaran dengan jari-jari = 2.5
 *
 * @param jari_jari     panjang jari-jari
 * @return              pointer ke Lingkaran yang dibuat
 */
Lingkaran *new_lingkaran(float jari_jari);

/**
 * @brief Membuat silinder dari Lingkaran sebagai alas dan nilai tinggi
 *
 * @note
 * Misal:
 *    Jari-jari Lingkaran = 2.5
 *    Tinggi Silinder = 3
 *
 * @example
 *    Lingkaran l = {...};
 *    Silinder *s = new_silinder(l, 3.0f);
 *    // untuk Silinder s, panjang jari-jari = 2.5, tinggi = 3.0
 *
 * @param l         panjang jari-jari
 * @param tinggi    tinggi Silinder
 * @return          pointer ke Silinder yang dibuat
 */
Silinder *new_silinder(const Lingkaran &l, float tinggi);

/**
 * @brief Assign nilai properti Silinder dari nilai jari-jari dan tinggi
 *
 * @note
 * Misal:
 *    Jari-jari Silinder = 2.5
 *    Tinggi Silinder = 3
 *
 * @example
 *    Silinder s = {};
 *    new_silinder(&s, 2.5, 3);
 *    // untuk Silinder s, panjang jari-jari = 2.5, tinggi = 3
 *
 * @param s             pointer ke Silinder yang akan diinisialisasi
 * @param jari_jari     panjang jari-jari
 * @param tinggi        tinggi Silinder
 */
void new_silinder(Silinder *s, float jari_jari, float tinggi);

/**
 * @brief Assign nilai panjang, lebar, dan tinggi dari sebuah Balok
 *
 * @param b             pointer ke Balok yang akan diinisialisasi
 * @param panjang       panjang balok
 * @param lebar         lebar balok
 * @param tinggi        tinggi balok
 */
void new_balok(Balok *b, float panjang, float lebar, float tinggi);

/**
 * @brief Mencari diameter Lingkaran
 *
 * @param l   Lingkaran yang akan diproses
 * @return    panjang diameter Lingkaran tersebut
 */
float cari_diameter(const Lingkaran &l);

/**
 * @brief Mencari diameter Silinder
 *
 * @param s   Silinder yang akan diproses
 * @return    panjang diameter Silinder tersebut
 */
float cari_diameter(const Silinder &s);

/**
 * @brief Mencari keliling alas Lingkaran
 *
 * @param l   Lingkaran yang akan diproses
 * @return    keliling Lingkaran tersebut
 */
float cari_keliling(const Lingkaran &l);

/**
 * @brief Mencari keliling alas Silinder
 *
 * @param s   Silinder yang akan diproses
 * @return    keliling alas Silinder tersebut
 */
float cari_keliling(const Silinder &s);

/**
 * @brief Mencari luas Lingkaran
 *
 * @param l         Lingkaran yang akan diproses
 * @return          luas Lingkaran
 */
float cari_luas(const Lingkaran &l);

/**
 * @brief Mencari luas alas Silinder
 *
 * @param s         Silinder yang akan diproses
 * @return          luas alas Silinder tersebut
 */
float cari_luas(const Silinder &s);

/**
 * @brief Mencari luas Balok
 *
 * @param b         Balok yang akan diproses
 * @return          luas Balok
 */
float cari_luas(const Balok &b);

/**
 * @brief Mencari volume Silinder
 *
 * @param s         Silinder yang akan diproses
 * @return          volume Silinder tersebut
 */
float cari_volume(const Silinder &s);

/**
 * @brief Mencari volume Balok
 *
 * @param b         Balok yang akan diproses
 * @return          volume Balok tersebut
 */
float cari_volume(const Balok &b);
