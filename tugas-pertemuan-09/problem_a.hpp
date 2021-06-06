#pragma once

#include "bst.hpp"

using namespace strukdat::bst;

/**
 * @brief   Melakukan traversal tree menggunakan Breadth First Search (BFS)
 * @note    Boleh dibuat secara rekursif maupun iteratiF
 * @example
 *  Misal terdapat tree:
 *          5
 *        /  \
 *       3    8
 *     /  \
 *    1    4
 * 
 *  BFS : 5 3 8 1 4
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T>
void BFSTraversal(Tree<T>& Root, vector<T>& traversedData);

/**
 * @brief   Mencari Lowest Common Ancestor (LCA) dari dua element tree
 * @note    N/A
 * @example
 *  Menurut Wikipedia, Lowest Common Ancestor dari elemen a dan b adalah elemen terdekat pada suatu tree
 *  yang memiliki keturunan a dan b (dengan catatan suatu elemen dapat menjadi keturunannya sendiri)
 * 
 * @see     https://en.wikipedia.org/wiki/Lowest_common_ancestor
 * 
 * @param Root   pointer ke root tree
 * @param a      pointer ke elemen pertama
 * @param b      pointer ke elemen kedua
 * 
 * @return       pointer ke elemen LCA nya
 */
template <typename T>
Tree<T> lowestCommonAncestor(Tree<T>& Root, pointer<T> a, pointer<T> b);

/**
 * @brief   Menginversi susunan tree tanpa membuat tree baru
 * @note    N/A
 * @example
 *  Misal terdapat tree:
 *          5
 *        /  \
 *       3    8
 *     /  \
 *    1    4
 *  BFS : 5 3 8 1 4
 * 
 *  Inverted:
 *          5
 *        /  \
 *       8    3
 *          /  \
 *         4    1
 *  BFS : 5 8 3 4 1
 * @param Root   pointer ke root tree
 * 
 * @return       pointer ke root tree
 */
template <typename T>
Tree<T> invertBST(Tree<T>& Root);