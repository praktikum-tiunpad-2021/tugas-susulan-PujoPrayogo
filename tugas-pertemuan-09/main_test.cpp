#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "problem_a.cpp"

using namespace strukdat::bst;

TEST_CASE("dapat mengisi tree", "[case_1]") {
  vector<int> v1{5, 2, 4, 7, 9};
  Root<int> = createTree<int>();

  for (auto &i : v1)
    insertBST(Root<int>, createElement(i));

  pointer<int>  e5 = search(Root<int>, 5),
                e2 = search(Root<int>, 2),
                e7 = search(Root<int>, 7);
  REQUIRE(e5->left->data == 2);
  REQUIRE(e2->left == nullptr);
  REQUIRE(e5->left->right == e2->right);
  REQUIRE(e7->right->data == 9);
}

TEST_CASE("dapat melakukan dfs traversal", "[case_2]") {
  vector<int> v1   = {8, 4, 12, 1, 6, 9, 5, 7},
              pre  = {8, 4, 1, 6, 5, 7, 12, 9},
              in   = {1, 4, 5, 6, 7, 8, 9, 12},
              post = {1, 5, 7, 6, 4, 9, 12, 8},
              v2;
  Root<int> = createTree<int>();
  for (auto &i : v1)
    insertBST(Root<int>, createElement(i));

  preOrder(Root<int>, v2);
  for (size_t i = 0; i < v1.size(); ++i)
    REQUIRE(v2[i] == pre[i]);
  v2.clear();

  inOrder(Root<int>, v2);
  for (size_t i = 0; i < v1.size(); ++i)
    REQUIRE(v2[i] == in[i]);
  v2.clear();

  postOrder(Root<int>, v2);
  for (size_t i = 0; i < v1.size(); ++i)
    REQUIRE(v2[i] == post[i]);
  v2.clear();
}

TEST_CASE("dapat melakukan bfs traversal", "[case_3]") {
  vector<int> v1  = {4, 10, 7, 5, 2, 3},
              v1a = {4, 2, 10, 3, 7, 5},
              v2  = {23, 51, 34, 11, 25, 6, 47, 49, 75, 38},
              v2a = {23, 11, 51, 6, 34, 75, 25, 47, 38, 49},
              vAns;
  Root<int> = createTree<int>();
  for (auto &i : v1)
    insertBST(Root<int>, createElement(i));

  BFSTraversal(Root<int>, vAns);
  for (size_t i = 0; i < v1.size(); ++i)
    REQUIRE(vAns[i] == v1a[i]);
  vAns.clear();

  Root<int> = createTree<int>();
  for (auto &i : v2)
    insertBST(Root<int>, createElement(i));

  BFSTraversal(Root<int>, vAns);
  for (size_t i = 0; i < v2.size(); ++i)
    REQUIRE(vAns[i] == v2a[i]);
  vAns.clear();
}

TEST_CASE("dapat menentukan lowest common ancestor", "[case_4]") {
  vector<int> v1 = {11, 8, 13, 2, 9, 15, 7};

  Root<int> = createTree<int>();
  for (auto &i : v1)
    insertBST(Root<int>, createElement(i));

  Tree<int> lca1 = lowestCommonAncestor(Root<int>, search(Root<int>, 8), search(Root<int>, 13));
  Tree<int> lca2 = lowestCommonAncestor(Root<int>, search(Root<int>, 7), search(Root<int>, 9));
  Tree<int> lca3 = lowestCommonAncestor(Root<int>, search(Root<int>, 13), search(Root<int>, 15));

  REQUIRE(lca1 == Root<int>);
  REQUIRE(lca1->data == 11);
  REQUIRE(lca2 == Root<int>->left);
  REQUIRE(lca2->data == 8);
  REQUIRE(lca3 == Root<int>->right);
  REQUIRE(lca3->data == 13);
}

TEST_CASE("dapat menginversi tree", "[case_5]") {
  vector<int> v1  = {3, 1, 5, 4},
              v1a = {3, 5, 1, 4},
              v2  = {22, 13, 56, 5, 18, 37, 82},
              v2a = {22, 56, 13, 82, 37, 18, 5},
              vAns;
  Root<int> = createTree<int>();
  for (auto &i : v1)
    insertBST(Root<int>, createElement(i));

  Root<int> = invertBST(Root<int>);
  BFSTraversal(Root<int>, vAns);
  for (size_t i = 0; i < v1.size(); ++i)
    REQUIRE(vAns[i] == v1a[i]);
  vAns.clear();

  Root<int> = createTree<int>();
  for (auto &i : v2)
    insertBST(Root<int>, createElement(i));

  Root<int> = invertBST(Root<int>);
  BFSTraversal(Root<int>, vAns);
  for (size_t i = 0; i < v2.size(); ++i)
    REQUIRE(vAns[i] == v2a[i]);
  vAns.clear();
}