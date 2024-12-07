#include "util/lazy_segment_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

#include "util/test.h"

int main() {
  util::lazy_segment_tree<uint32_t> st(
      4, std::numeric_limits<uint32_t>::lowest(),
      [](auto l, auto r) { return std::max(l, r); });
  TEST(st.buffer_size(), 7);
  TEST(st.leaf_size(), 4);
  st.update(0, 10);
  st.update(3, 15);
  TEST(st.query(0, 4), 15);
  TEST(st.query(0, 3), 10);
  TEST(st.query(0, 2), 10);
  TEST(st.query(0, 1), 10);
  TEST(st.query(1, 4), 15);
}