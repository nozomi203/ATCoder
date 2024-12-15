#include "util/lazy_segment_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

#include "util/test.h"

int main() {
  using S = uint32_t;
  constexpr S kSIdentity = std::numeric_limits<S>::lowest();
  using F = uint32_t;
  constexpr F kFIdentity = std::numeric_limits<S>::lowest();
  constexpr auto kOpFunc = [](S l, S r) -> S { return std::max(l, r); };
  constexpr auto kMappingFunc = [](F l, S r) -> S { return std::max(l, r); };
  constexpr auto kCompositionFunc = [](F l, F r) -> F {
    return std::max(l, r);
  };
  util::lazy_segment_tree<S, kSIdentity, F, kFIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      st(4);
  TEST(st.leaf_size(), 4);
  st.apply(0, 4, 10);
  st.apply(2, 4, 15);
  TEST(st.query(0, 4), 15);
  TEST(st.query(0, 3), 15);
  TEST(st.query(0, 2), 10);
  TEST(st.query(0, 1), 10);
  TEST(st.query(1, 4), 15);
}