#include "util/segment_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

#include "util/test.h"

int main() {
  // 区間取得関数
  using S = uint32_t;
  constexpr auto kSIdentity = std::numeric_limits<S>::lowest();
  constexpr auto kOpFunc = [](S l, S r) -> S { return std::max(l, r); };
  util::segment_tree<S, kSIdentity, kOpFunc> st(4);
  st.apply(0, 10);
  st.apply(3, 15);
  TEST(st.query(0, 4), 15);
  TEST(st.query(0, 3), 10);
  TEST(st.query(0, 2), 10);
  TEST(st.query(0, 1), 10);
  TEST(st.query(1, 4), 15);
}