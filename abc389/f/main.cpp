#include "util/binary_search.h"
#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 N;
  cin >> N;

  constexpr s64 max_size = 5 * 100000 + 2;
  vector<s64> values(max_size);
  for (s64 i = 0; i < values.size(); ++i) {
    values[i] = i;
  }
  values[max_size - 1] = numeric_limits<s64>::max();

  using S = s64;
  using F = s64;
  constexpr auto kOpFunc = [](S a, S b) { return max(a, b); };
  constexpr auto kMappingFunc = [](F f, S s) { return s + f; };
  constexpr auto kCompositionFunc = [](F a, F b) { return a + b; };
  util::lazy_segment_tree<S, F, 0, kOpFunc, kMappingFunc, kCompositionFunc> lst(
      values);

  for (s64 i = 0; i < N; ++i) {
    s64 l, r;
    cin >> l >> r;
    const auto [ok_l, ng_l] = util::binary_search<s64>(
        0LL, max_size - 1LL,
        [&](auto value) -> bool { return lst.query(value, value + 1) < l; });
    const auto [ok_r, ng_r] = util::binary_search<s64>(
        0LL, max_size - 1LL,
        [&](auto value) -> bool { return lst.query(value, value + 1) <= r; });

    if (ng_l < ng_r) lst.apply(ng_l, ng_r, 1);
  }

  s64 Q;
  cin >> Q;

  vector<s64> answers(Q);

  for (s64 i = 0; i < Q; ++i) {
    s64 query;
    cin >> query;
    answers[i] = lst.query(query, query + 1);
  }

  for (auto answer : answers) {
    cout << answer << endl;
  }
}