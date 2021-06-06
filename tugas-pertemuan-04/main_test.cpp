#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "problem_a.hpp"

TEST_CASE("Mengecek data integer berdasarkan parameter", "[case_1]")
{
  SingleNode *head, *newNode;
  head = nullptr;

  createSingleNode(newNode,9);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,5);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,1);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,7);
  insertSingleFirst(head,newNode);

  REQUIRE(dataAt(head,1) != 1);
  REQUIRE(dataAt(head,2) == 1);
  REQUIRE(dataAt(head,3) != 3);
  REQUIRE(dataAt(head,4) == 9);
}

TEST_CASE("Mengecek jumlah node yang ada di sebuah list", "[case_2]")
{
  DoubleNode *head, *newNode;
  head = nullptr;

  createDoubleNode(newNode,13);
  insertDoubleFirst(head,newNode);
  createDoubleNode(newNode,2);
  insertDoubleLast(head,newNode);
  createDoubleNode(newNode,7);
  insertDoubleFirst(head,newNode);
  createDoubleNode(newNode,9);
  insertDoubleLast(head,newNode);

  REQUIRE(nodeCount(head) == 4);

  deleteDoubleLast(head);
  REQUIRE(nodeCount(head) == 3);

  deleteDoubleFirst(head);
  REQUIRE(nodeCount(head) == 2);
}

TEST_CASE("Mengurutkan sebuah node secara ascending.", "[case_3]")
{
  SingleNode *head, *newNode;
  head = nullptr;

  createSingleNode(newNode,7);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,1);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,5);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,4);
  insertSingleFirst(head,newNode);
  createSingleNode(newNode,2);
  insertSingleFirst(head,newNode);

  sortAscending(head);

  SinglePointer tmp = head;
  while(tmp->nextNode != nullptr)
  {
    REQUIRE(tmp->data <= tmp->nextNode->data);
    tmp = tmp->nextNode;
  }
}

TEST_CASE("Membalikkan sebuah list dengan memasukkannya ke list yang baru.", "[case_4]")
{
  SingleNode *head, *headReverse, *newNode;
  head = nullptr;
  headReverse = nullptr;

  createSingleNode(newNode,8);
  insertSingleLast(head,newNode);
  createSingleNode(newNode,4);
  insertSingleLast(head,newNode);
  createSingleNode(newNode,0);
  insertSingleLast(head,newNode);
  createSingleNode(newNode,6);
  insertSingleLast(head,newNode);
  createSingleNode(newNode,1);
  insertSingleLast(head,newNode);

  reverseList(head,headReverse);

  SinglePointer tmp = head;
  SinglePointer tmpReverse = headReverse;
  int j = nodeCount(head);
  for(int i = 1; i <= nodeCount(head); i++)
  {
    REQUIRE(dataAt(tmp,i) == dataAt(tmpReverse,j));
    j--;
  }
}