#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;

  using S = s64;
  using F = s64;
  constexpr S kSIdentity = 0;
  constexpr auto kOp = [](S l, S r) -> S { return max(l, r); };
  constexpr auto kMapping = [](F l, [[maybe_unused]] S r) -> S { return l; };
  constexpr auto kComposition = [](F l, [[maybe_unused]] F r) -> F {
    return l;
  };
  util::lazy_segment_tree<S, F, kSIdentity, kOp, kMapping, kComposition> lst(N,

                                                                             0);
  vector<s64> answers;
  for (s64 q = 0; q < Q; ++q) {
    s64 query;
    cin >> query;
    if (query == 1) {
      s64 pos, x;
      cin >> pos >> x;
      lst.apply(pos - 1, pos, x);
    } else {
      s64 l, r;
      cin >> l >> r;
      answers.push_back(lst.query(l - 1, r - 1));
    }
  }

  for (auto answer : answers) {
    cout << answer << endl;
  }
}