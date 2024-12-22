#include "util/union_find_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

#include "util/test.h"

int main() {
  util::union_find_tree uft(4);
  TEST(uft.same(0, 0), true);
  TEST(uft.same(0, 1), false);
  TEST(uft.same(0, 2), false);
  TEST(uft.same(0, 3), false);
  TEST(uft.unite(0, 1), 0);
  TEST(uft.same(0, 1), true);
  TEST(uft.same(1, 2), false);
  TEST(uft.union_size(0), 2);
}