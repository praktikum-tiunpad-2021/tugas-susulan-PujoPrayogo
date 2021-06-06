#pragma once

#include <vector>
using std::vector;

namespace strukdat {

namespace bst {

/**
 * @brief   Node tree berisi nilai bertipe `T` yang disimpan pada `data`
 */
template <typename T>
struct Node {
  T data;
  Node *left;
  Node *right;
};

/**
 * @brief   Tipe pointer dari node
 */
template <typename T>
using pointer = Node<T>*;

/**
 * @brief   Alias untuk pointer
 */
template <typename T>
using Tree = pointer<T>;

template <typename T>
Tree<T> Root;

/**
 * @brief    Fungsi untuk membuat tree baru
 * 
 * @return   simply nullptr:)
 */
template <typename T>
Tree<T> createTree() { return nullptr; }

/**
 * @brief   Membuat dan menginisialisasi element baru untuk dimasukkan ke tree
 * @param data   data yang akan dimasukkan
 * 
 * @return       pointer ke elemen baru
 */
template <typename T>
pointer<T> createElement(T data) {
  // TODO: Implementasikan!
}

/**
 * @brief   Mengecek apakah elemen yang dipass memiliki data yang lebih besar dibanding root tree
 * @param Root           pointer ke element parent/ root
 * @param checkElement   pointer ke element yang di cek
 * 
 * @return              'true' jika data pada checkElement lebih besar dari data root,
 *                      'false' jika sebaliknya
 */
template <typename T>
bool isHigherThanRoot(Tree<T>& Root, pointer<T>& checkElement) {
  // TODO: Implementasikan!
}

/**
 * @brief   Memasukkan element ke dalam tree
 * @note    Implementasikan secara rekursif
 * @param Root         pointer ke element parent/ root
 * @param newElement   pointer ke element baru
 */
template <typename T>
void insertBST(Tree<T>& Root, pointer<T> newElement) {
  // TODO: Implementasikan!
}

/**
 * @brief   Mencari element dalam tree
 * @note    Implementasikan secara rekursif
 * @param Root   pointer ke element parent/ root
 * @param data   data yang ingin dicari
 * 
 * @return       pointer element yang dicari
 */
template <typename T>
pointer<T> search(Tree<T>& Root, T data) {
  // TODO: Implementasikan!
}

/**
 * @brief   Melakukan traversal tree secara preOrder (P->L->R)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T>
void preOrder(Tree<T>& Root, vector<T>& traversedData) {
  // TODO: Implementasikan!
}

/**
 * @brief   Melakukan traversal tree secara inOrder (L->P->R)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T>
void inOrder(Tree<T>& Root, vector<T>& traversedData) {
  // TODO: Implementasikan!
}

/**
 * @brief   Melakukan traversal tree secara postOrder (L->R->P)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T>
void postOrder(Tree<T>& Root, vector<T>& traversedData) {
  // TODO: Implementasikan!
}

}  // namespace bst

}  // namespace strukdat
