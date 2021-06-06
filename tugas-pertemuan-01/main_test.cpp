#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "problem_a.hpp"

TEST_CASE("bilangan dicek prima atau tidak", "[case_1]")
{
  REQUIRE(is_prime(2) == true);
  REQUIRE(is_prime(181) == true);
  REQUIRE(is_prime(5903) == true);
  REQUIRE(is_prime(498) == false);
  REQUIRE(is_prime(0) == false);
  REQUIRE(is_prime(-2) == false);
}

TEST_CASE("hasil faktorial terhitung", "[case_2]")
{
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(0) == 1);
  REQUIRE(factorial(10) == 3628800);
}

TEST_CASE("integer array di-sort ascending secara in-place", "[case_3]")
{
  int arr1[]{3, 5, 3, 2, 1};
  const int arr1_sorted[]{1, 2, 3, 3, 5};
  inplace_sort(5, arr1);
  for (size_t i = 0; i < 5; ++i)
  {
    REQUIRE(arr1[i] == arr1_sorted[i]);
  }

  int arr2[]{0, 0, -1, 0};
  const int arr2_sorted[]{-1, 0, 0, 0};
  inplace_sort(4, arr2);
  for (size_t i = 0; i < 4; ++i)
  {
    REQUIRE(arr2[i] == arr2_sorted[i]);
  }
}

TEST_CASE("string terbalik secara in-place", "[case_4]")
{
  std::string str;

  str = "John Doe";
  inplace_reverse_str(str);
  REQUIRE(str.compare("eoD nhoJ") == 0);

  str = "1234";
  inplace_reverse_str(str);
  REQUIRE(str.compare("4321") == 0);

  str = "";
  inplace_reverse_str(str);
  REQUIRE(str.compare("") == 0);

  str = "ABCD";
  inplace_reverse_str(str);
  REQUIRE(str.compare("CDBA") != 0);
}

TEST_CASE("string terbalik", "[case_5]")
{
  REQUIRE(reverse_str("John Doe").compare("eoD nhoJ") == 0);
  REQUIRE(reverse_str("1234").compare("4321") == 0);
  REQUIRE(reverse_str("").compare("") == 0);
  REQUIRE(reverse_str("ABCD").compare("CDBA") != 0);
}