#include "util/lazy_segment_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

#include "util/test.h"

int main() {
  using S = uint32_t;
  using F = uint32_t;
  constexpr S kSIdentity = std::numeric_limits<S>::lowest();
  constexpr F kFIdentity = std::numeric_limits<S>::lowest();
  constexpr auto kOpFunc = [](S l, S r) -> S { return std::max(l, r); };
  constexpr auto kMappingFunc = [](F l, S r) -> S { return std::max(l, r); };
  constexpr auto kCompositionFunc = [](F l, F r) -> F {
    return std::max(l, r);
  };

  util::lazy_segment_tree<S, F, kSIdentity, kFIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      st(4);
  TEST(st.query(0, 4), 0);
  st.apply(2, 4, 10);
  TEST(st.query(0, 3), 10);
}