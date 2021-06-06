#pragma once

#include "list.hpp"

/**
 * @brief       Membuat sebuah single node baru.
 * 
 * @param newNode     Node baru dengan data integer sesuai parameter.
 * 
 */
void createSingleNode(SinglePointer& newNode, int data);

/**
 * @brief       Menambahkan sebuah node di awal.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 * @param newNode     Node yang akan ditambahkan ke head.
 * 
 */
void insertSingleFirst(SinglePointer& head, SinglePointer newNode);

/**
 * @brief       Menambahkan sebuah node di akhir.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 * @param newNode     Node yang akan ditambahkan ke head.
 * 
 */
void insertSingleLast(SinglePointer& head, SinglePointer newNode);

/**
 * @brief       Membuat sebuah double node baru.
 * 
 * @param newNode     Node baru dengan data integer sesuai parameter.
 * 
 */
void createDoubleNode(DoublePointer& newNode, int data);

/**
 * @brief       Menambahkan sebuah node di awal.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 * @param newNode     Node yang akan ditambahkan ke head.
 * 
 */
void insertDoubleFirst(DoublePointer& head, DoublePointer newNode);

/**
 * @brief       Menambahkan sebuah node di akhir.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 * @param newNode     Node yang akan ditambahkan ke head.
 * 
 */
void insertDoubleLast(DoublePointer& head, DoublePointer newNode);

/**
 * @brief       Menghapuskan sebuah node di awal.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 */
void deleteDoubleFirst(DoublePointer& head);

/**
 * @brief       Menghapuskan sebuah node di akhir.
 * 
 * @param head     Node yang menjadi muka dari sebuah list.
 * 
 */
void deleteDoubleLast(DoublePointer& head);

/**
 * @brief       Menghitung jumlah node yang ada di list.
 * 
 * @param head  Node yang menjadi muka dari sebuah double linked list.
 * 
 * @return      Jumlah node yang ada di list.
 */
int nodeCount(DoublePointer head);

/**
 * @brief       Menghitung jumlah node yang ada di list.
 * 
 * @param head  Node yang menjadi muka dari sebuah single linked list.
 * 
 * @return      Jumlah node yang ada di list.
 */
int nodeCount(SinglePointer head);

/**
 * @brief       Melihat nilai data yang ada di list berdasarkan parameter.
 * 
 * @note 
 *    Sebuah list dengan isi [head -> 1 -> 4 -> 7 -> 2]
 *    dataAt(head, 3) harus mengembalikan nilai 7
 * 
 * @param head  Node yang menjadi muka dari sebuah list.
 * 
 * @param index Urutan node di list yang ingin dicari nilainya.
 * 
 * @return      Jumlah node yang ada di list.
 */
int dataAt(SinglePointer head, int index);

/**
 * @brief       Mengurutkan list secara ascending.
 * 
 * @param head  Node yang menjadi muka dari sebuah list.
 * 
 */
void sortAscending(SinglePointer& head);

/**
 * @brief       Membalikkan list dengan memasukkannya ke list baru.
 * 
 * @param head  Node yang menjadi muka dari sebuah list.
 * 
 * @param reverseHead  Node yang merupakan kebalikan dari head.
 * 
 */
void reverseList(SinglePointer& head, SinglePointer& reverseHead);