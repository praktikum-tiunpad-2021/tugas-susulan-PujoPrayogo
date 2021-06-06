#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "problem_a.hpp"

TEST_CASE("mengembalikan dua kali nilai dengan pointer", "[case_1]")
{
  int num1 = 8, *ptr1 = multiply_by_two(num1);
  REQUIRE((*ptr1 == 16 && ptr1 == &num1));
  int num2 = 51, *ptr2 = multiply_by_two(num2);
  REQUIRE((*ptr2 == 102 && ptr2 == &num2));
  int num3 = 0, *ptr3 = multiply_by_two(num3);
  REQUIRE((*ptr3 == 0 && ptr3 == &num3));
  int num4 = -12, *ptr4 = multiply_by_two(num4);
  REQUIRE((*ptr4 == -24 && ptr4 == &num4));
}

TEST_CASE("mengembalikan string berisi karakter ke-3 dan ke-5", "[case_2]")
{
  char str1[] = "Maria";
  REQUIRE(the_third_and_fifth(str1).compare("ra") == 0);
  char str2[] = "9876543";
  REQUIRE(the_third_and_fifth(str2).compare("75") == 0);
  char str3[] = "_C_ReS";
  REQUIRE(the_third_and_fifth(str3).compare("_e") == 0);
  char str4[] = "MILTONIA";
  REQUIRE(the_third_and_fifth(str4).compare("LS") != 0);
}

TEST_CASE("mencari panjang maksimum array", "[case_3]")
{
  char str1[] = "John";
  REQUIRE(my_own_strlen(str1) == 4);
  char str2[] = "ignisfatuus";
  REQUIRE(my_own_strlen(str2) == 11);
  char str3[] = "";
  REQUIRE(my_own_strlen(str3) == 0);
  char str4[] = "ThroughDifficultiesToTheStars";
  REQUIRE(my_own_strlen(str4) == 29);
}

TEST_CASE("menukar dua elemen dalam array", "[case_4]")
{
  int arr1[]{1, 2, 3}, arr2[]{4, 1, 9};
  int arr1_swap[]{1, 1, 3}, arr2_swap[]{4, 2, 9};
  element_swapper(arr1, arr2, 1);
  for (size_t i = 0; i < 3; ++i)
  {
    REQUIRE((arr1[i] == arr1_swap[i] && arr2[i] == arr2_swap[i]));
  }

  int arr3[]{0, 8, 18, 10, 2}, arr4[]{11, 12, 9, 3, 6};
  int arr3_swap[]{0, 8, 9, 3, 2}, arr4_swap[]{11, 12, 18, 10, 6};
  element_swapper(arr3, arr4, 3);
  element_swapper(arr3, arr4, 2);
  for (size_t i = 0; i < 5; ++i)
  {
    REQUIRE((arr3[i] == arr3_swap[i] && arr4[i] == arr4_swap[i]));
  }
}
