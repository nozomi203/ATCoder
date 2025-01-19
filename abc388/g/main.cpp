#include "util/binary_search.h"
#include "util/common.h"
#include "util/segment_tree.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];

  vector<s64> diffs(N);
  for (s64 i{0}, j{0}; i < N; ++i) {
    while (j < N && A[i] * 2 > A[j]) ++j;
    diffs[i] = j - i;
  }

  using S = s64;
  constexpr S kSIdentity = 0;
  constexpr auto kOpFunc = [](S l, S r) -> S { return max(l, r); };
  util::segment_tree<S, kSIdentity, kOpFunc> st(diffs);

  s64 Q;
  cin >> Q;
  vector<pair<s64, s64>> lr(Q);
  for (s64 i = 0; i < Q; ++i) {
    cin >> lr[i].first >> lr[i].second;
    --lr[i].first;
  }

  vector<s64> answers;
  for (s64 i = 0; i < Q; ++i) {
    auto [l, r] = lr[i];
    // 鏡餅の数の最大を探索
    auto [ok, ng] = util::binary_search<s64>(0, r - l, [&](s64 value) -> bool {
      auto q = st.query(l, l + value);
      return l + value - 1 + max(q, value) < r;
    });
    answers.push_back(ok);
  }

  for (auto answer : answers) {
    cout << answer << endl;
  }
}