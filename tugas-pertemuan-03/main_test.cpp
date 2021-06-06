#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "shape.hpp"
#include "problem_a.hpp"
#include <cmath>

template<typename T>
constexpr bool almost_equal(const T &x, const T &y) {
  return std::fabs(x - y) <= 0.1;
}

TEST_CASE("melakukan operasi pada lingkaran", "[case_1]")
{
  float jari_jari;
  Lingkaran *lp;
  Lingkaran l;

  jari_jari = 2.5f;

  lp = new_lingkaran(jari_jari);
  REQUIRE(lp != nullptr);
  REQUIRE(sizeof(*lp) == sizeof(Lingkaran));

  l = *new_lingkaran(jari_jari);
  REQUIRE(almost_equal(cari_keliling(l), 15.7f));
  REQUIRE(almost_equal(cari_luas(l), 19.625f));
  REQUIRE(almost_equal(cari_diameter(l), 5.0f));

  jari_jari = 25.8f;

  lp = new_lingkaran(jari_jari);
  REQUIRE(lp != nullptr);
  REQUIRE(sizeof(*lp) == sizeof(Lingkaran));

  l = *new_lingkaran(jari_jari);
  REQUIRE(almost_equal(cari_keliling(l), 162.024f));
  REQUIRE(almost_equal(cari_luas(l), 2090.11f));
  REQUIRE(almost_equal(cari_diameter(l), 51.6f));
}

TEST_CASE("melakukan operasi pada silinder", "[case_2]")
{
  float jari_jari, tinggi;
  Lingkaran l;
  Silinder *sp;
  Silinder s{};

  jari_jari = 2.5f;
  tinggi = 10.2f;

  l = *new_lingkaran(jari_jari);
  sp = new_silinder(l, tinggi);
  REQUIRE(sp != nullptr);
  REQUIRE(sizeof(*sp) == sizeof(Silinder));

  new_silinder(&s, jari_jari, tinggi);
  REQUIRE(almost_equal(cari_keliling(s), 15.7f));
  REQUIRE(almost_equal(cari_luas(s), 19.625f));
  REQUIRE(almost_equal(cari_diameter(s), 5.0f));
  REQUIRE(almost_equal(cari_volume(s), 200.175f));

  jari_jari = 19.5f;
  tinggi = 16.2f;

  l = *new_lingkaran(jari_jari);
  sp = new_silinder(l, tinggi);
  REQUIRE(sp != nullptr);
  REQUIRE(sizeof(*sp) == sizeof(Silinder));

  new_silinder(&s, jari_jari, tinggi);

  REQUIRE(almost_equal(cari_keliling(s), 122.46f));
  REQUIRE(almost_equal(cari_luas(s), 1193.99f));
  REQUIRE(almost_equal(cari_diameter(s), 39.0f));
  REQUIRE(almost_equal(cari_volume(s), 19342.6f));
}

TEST_CASE("melakukan operasi pada balok", "[case_3]")
{
  float panjang, lebar, tinggi;
  Balok b{};

  panjang = 2.0f;
  lebar = 1.0f;
  tinggi = 1.5f;

  new_balok(&b, panjang, lebar, tinggi);
  REQUIRE(almost_equal(cari_luas(b), 13.0f));
  REQUIRE(almost_equal(cari_volume(b), 3.0f));
}
