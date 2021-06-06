/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 * Di bawah merupakan contoh untuk memanggil fungsi traversal tree
 */

#include <iostream>
#include "bst.hpp"
using namespace strukdat::bst;

// dfs wrapper
template <typename T>
void DFSTraversal(void (*traversal)(Tree<T> &, vector<T> &), Tree<T> &Root)
{
  vector<int> traversedData;
  traversal(Root, traversedData);
  for (auto &i : traversedData)
    std::cout << i << ' ';
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  pointer<int> newElement;
  Root<int> = createTree<int>();
  vector<int> initialData = {5, 3, 7, 1, 4, 6, 8, 2, 9};

  for (auto &i : initialData)
    insertBST(Root<int>, createElement(i));

  DFSTraversal(preOrder, Root<int>);
  DFSTraversal(inOrder, Root<int>);
  DFSTraversal(postOrder, Root<int>);

  return 0;
}