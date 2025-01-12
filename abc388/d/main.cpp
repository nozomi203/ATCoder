#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
  }

  using S = s64;
  using F = s64;
  constexpr S kSIdentity = numeric_limits<s64>::min();
  constexpr auto kOpFunc = [](S a, S b) -> S { return max(a, b); };
  constexpr auto kMappingFunc = [](F f, S s) -> S { return s + f; };
  constexpr auto kCompositionFunc = [](F f0, F f1) -> F { return f0 + f1; };
  util::lazy_segment_tree<S, F, kSIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      lst(A);

  for (s64 i = 0; i < N - 1; ++i) {
    const s64 stone_count = lst.query(i, i + 1);
    const s64 drop_count = min(stone_count, N - i - 1);
    const s64 idx_r = i + drop_count + 1;
    if (drop_count > 0) {
      lst.apply(i, i + 1, -drop_count);
      lst.apply(i + 1, idx_r, 1);
    }
  }

  for (s64 i = 0; i < N; ++i) {
    const auto q = lst.query(i, i + 1);
    cout << q;
    if (i < N - 1) cout << " ";
  }
  cout << endl;
}