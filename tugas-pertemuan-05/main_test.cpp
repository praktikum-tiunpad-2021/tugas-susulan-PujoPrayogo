#define CATCH_CONFIG_MAIN
#include <string>
#include <unordered_map>
#include <vector>

#include "catch.hpp"
#include "list.hpp"

using namespace strukdat::circular_list;

struct Karyawan {
  std::string nip;
  std::string nama;

  Karyawan() = default;
  Karyawan(const std::string &_nip, const std::string &_nama)
      : nip(_nip), nama(_nama) {}
  bool operator==(const Karyawan &oth) const {
    return nip == oth.nip && nama == oth.nama;
  }
  bool operator!=(const Karyawan &oth) const {
    return nip != oth.nip || nama != oth.nama;
  }
};

struct Divisi {
  std::string nama;
  NodePtr<Karyawan> k_list;

  Divisi() = default;
  Divisi(const std::string &_nama, NodePtr<Karyawan> _k_list)
      : nama(_nama), k_list(_k_list) {}
  bool operator==(const Divisi &oth) const { return nama == oth.nama; }
  bool operator!=(const Divisi &oth) const { return nama != oth.nama; }
};

TEST_CASE("dapat melakukan operasi dasar linked list", "[case_1]") {
  NodePtr<int> head = new_list<int>();

  push_front(head, 50);
  auto pos1 = push_front(head, 36);
  push_back(head, 123);
  insert_after(pos1, 386);
  if (auto pos2 = find(head, 123)) {
    insert_after(pos2, 298);
  }

  const std::vector<int> key_1 = {36, 386, 50, 123, 298};
  std::vector<int> ans_1;
  for_each(head, [&ans_1](const int &n) { ans_1.push_back(n); });

  for (size_t i = 0; i < key_1.size(); ++i) {
    REQUIRE(key_1[i] == ans_1[i]);
  }

  erase(head, pos1);

  if (auto pos2 = find(head, 54)) {
    insert_after(pos2, 988);
  }

  const std::vector<int> key_2 = {386, 50, 123, 298};
  std::vector<int> ans_2;
  for_each(head, [&ans_2](const int &n) { ans_2.push_back(n); });

  for (size_t i = 0; i < key_2.size(); ++i) {
    REQUIRE(key_2[i] == ans_2[i]);
  }

  destroy_list(head);
}

TEST_CASE("dapat dilakukan nesting pada linked list", "[case_2]") {
  const std::unordered_map<std::string, std::vector<Karyawan>> k_map_key = {
      {"HRD", {Karyawan("H001", "Budi")}},
      {"Produksi", {Karyawan("H002", "Cica")}},
      {"Pemasaran", {Karyawan("P001", "Santi"), Karyawan("P002", "Heri")}}

  };

  auto d_head = new_list<Divisi>();
  for (const auto &kv : k_map_key) {
    auto k_head = new_list<Karyawan>();
    for (const auto &karyawan : kv.second) {
      push_back(k_head, karyawan);
    }
    push_back(d_head, Divisi(kv.first, k_head));
  }

  std::unordered_map<std::string, std::vector<Karyawan>> k_map_ans;

  for_each(d_head, [&k_map_ans](const Divisi &d) {
    k_map_ans[d.nama] = {};
    for_each(d.k_list, [&k_map_ans, &d](const Karyawan &k) {
      k_map_ans[d.nama].push_back(Karyawan(k.nip, k.nama));
    });
  });

  REQUIRE(k_map_ans == k_map_key);

  for_each(d_head, [&k_map_ans](const Divisi &d) { destroy_list(d.k_list); });
  destroy_list(d_head);
}