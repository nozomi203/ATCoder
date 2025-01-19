#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 N;
  cin >> N;

  using S = s64;
  using F = s64;
  constexpr auto kOpFunc = [](S a, S b) { return a; };
  constexpr auto kMappingFunc = [](F f, S s) { return s + f; };
  constexpr auto kCompositionFunc = [](F a, F b) { return a + b; };
  util::lazy_segment_tree<S, F, 0, kOpFunc, kMappingFunc, kCompositionFunc> lst(
      N, 0);
}