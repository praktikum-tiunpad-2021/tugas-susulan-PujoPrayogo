#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "problem_a.cpp"

using namespace strukdat::stack;
TEST_CASE("dapat membuat stack baru", "[case_1]") {
  Top<int> = createStack(Top<int>);
  REQUIRE(Top<int> == nullptr);
}

TEST_CASE("dapat membuat elemen baru dengan pointer", "[case_2]") {
  pointer<int> elementInt;
  pointer<float> elementFloat;
  createElement(elementInt, 66);
  createElement(elementFloat, 48.4f);
  REQUIRE(elementFloat->data == 48.4f);
  REQUIRE(elementInt->data == 66);
  REQUIRE(elementInt->next == nullptr);
}

TEST_CASE("dapat mengambil puncak dari stack", "[case_3]") {
  pointer<int> newElement;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
  }
  REQUIRE(peek(Top<int>) == 25);
}

TEST_CASE("dapat mengecek stack kosong", "[case_4]") {
  pointer<int> newElement;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);
  REQUIRE(isEmpty(Top<int>) == true);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
    REQUIRE(isEmpty(Top<int>) == false);
  }
}

TEST_CASE("dapat menambah elemen pada stack (push)", "[case_5]") {
  pointer<int> newElement;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
    REQUIRE(Top<int>->data == data[i]);
  }
}

TEST_CASE("dapat menghapus elemen pada stack (pop)", "[case_6]") {
  pointer<int> newElement, pDel;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);

  pDel = pop(Top<int>, pDel);
  REQUIRE(pDel == nullptr);

  createElement(newElement, 80);
  Top<int> = push(Top<int>, newElement);
  pDel = pop(Top<int>, pDel);
  REQUIRE(Top<int> == nullptr);
  REQUIRE(pDel->data == 80);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
  }

  pDel = pop(Top<int>, pDel);
  pDel = pop(Top<int>, pDel);
  pDel = pop(Top<int>, pDel);
  REQUIRE(pDel->data == 41);
}

TEST_CASE("dapat mencari elemen terdalam pada stack", "[case_7]") {
  pointer<int> newElement, pLast;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);
  
  pLast = lastNode(Top<int>);
  REQUIRE(pLast == nullptr);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
  }

  pLast = lastNode(Top<int>);
  REQUIRE(pLast->data == 87);
}

TEST_CASE("dapat mengambil elemen terbesar pada stack", "[case_8]") {
  pointer<int> newElement;
  int data[5] = {87, 90, 41, 85, 25};
  Top<int> = createStack(Top<int>);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data[i]);
    Top<int> = push(Top<int>, newElement);
  }

  REQUIRE(getMax(Top<int>) == 90);
}

TEST_CASE("dapat menentukan jumlah maksimal yang setara dari 3 stack", "[case_9]") {
  pointer<int> newElement;
  int data1[5] = { 3, 2, 1, 1, 1 };
  int data2[3] = { 4, 3, 2 };
  int data3[4] = { 1, 1, 4, 1 };

  Stack<int> Top1, Top2, Top3;
  Top1 = createStack(Top1);
  Top2 = createStack(Top2);
  Top3 = createStack(Top3);

  for (int i = 0; i < 5; i++) {
    createElement(newElement, data1[i]);
    Top1 = push(Top1, newElement);
  }
  for (int i = 0; i < 3; i++) {
    createElement(newElement, data2[i]);
    Top2 = push(Top2, newElement);
  }
  for (int i = 0; i < 4; i++) {
    createElement(newElement, data3[i]);
    Top3 = push(Top3, newElement);
  }

  REQUIRE(getEqualStack(Top1, Top2, Top3) == 7);
}

TEST_CASE("dapat menentukan apakah kurung yang diberikan seimbang atau tidak", "[case_10]") {
  REQUIRE(isBracketBalanced("{[()]}") == true);
  REQUIRE(isBracketBalanced("{[(])}") == false);
  REQUIRE(isBracketBalanced("{{[[(())]]}}") == true);
}
