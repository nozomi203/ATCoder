#include "util/lazy_segment_tree.h"

#include <cassert>
#include <cstdint>
#include <format>
#include <iostream>
#include <limits>
#include <random>

#include "util/dummy_segment_tree.h"
#include "util/test.h"

int main() {
  using S = uint32_t;
  using F = uint32_t;
  constexpr S kSIdentity = 0;
  constexpr auto kOpFunc = [](S l, S r) -> S { return std::max(l, r); };
  constexpr auto kMappingFunc = [](F l, S r) -> S { return l; };
  constexpr auto kCompositionFunc = [](F l, [[maybe_unused]] F r) -> F {
    return l;
  };
  // 区間加算→区間和
  util::lazy_segment_tree<S, F, kSIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      lst(8, 0);
  util::dummy_lazy_segment_tree<S, F, kSIdentity, kOpFunc, kMappingFunc,
                                kCompositionFunc>
      dlst(8, 0);

  std::mt19937 engine(1);
  std::uniform_real_distribution<float> dist(0.0f, 1.0f);

  for (uint32_t i = 0; i < 1000; ++i) {
    uint32_t query = std::floor(2 * dist(engine));
    if (query == 1) {
      uint32_t r = std::floor(8 * dist(engine)) + 1;
      uint32_t l = std::floor(r * dist(engine));
      uint32_t value = std::floor(10 * dist(engine));
      lst.apply(l, r, value);
      dlst.apply(l, r, value);
      std::cout << std::format("apply l:{},r:{},value:{}", l, r, value)
                << std::endl;
    } else {
      uint32_t r = std::floor(8 * dist(engine)) + 1;
      uint32_t l = std::floor(r * dist(engine));
      auto expected = dlst.query(l, r);
      auto returned = lst.query(l, r);
      bool result = (expected == returned);
      std::cout << std::format(
                       "query l:{},r:{},expected:{},returned:{},status:{}", l,
                       r, expected, returned,
                       (result ? "\033[32m[passed]\033[m"
                               : "\033[31m[failed]\033[m"))
                << std::endl;
    }
  }
}