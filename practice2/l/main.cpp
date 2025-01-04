#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;

  struct S {
    uint64_t num_zero{0};
    uint64_t num_one{0};
    uint64_t num_inversion{0};
  };
  vector<S> values(N);
  for (s64 n = 0; n < N; ++n) {
    s32 A;
    cin >> A;
    if (A) {
      values[n].num_one = 1;
    } else {
      values[n].num_zero = 1;
    }
  }

  constexpr S kSIdentity = S();
  using F = bool;
  constexpr auto kOpFunc = [](const S& l, const S& r) -> S {
    return S{l.num_zero + r.num_zero, l.num_one + r.num_one,
             l.num_inversion + r.num_inversion + l.num_one * r.num_zero};
  };
  constexpr auto kMappingFunc = [](const F& l, const S& r) -> S {
    if (l) {
      return S{r.num_one, r.num_zero, r.num_one * r.num_zero - r.num_inversion};
    }
    return r;
  };
  constexpr auto kCompositionFunc = [](const F& l, const F& r) -> F {
    if (l && r) return false;
    return l || r;
  };

  util::lazy_segment_tree<S, F, kSIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      lst(values);

  for (s64 q = 0; q < Q; ++q) {
    s64 T, L, R;
    cin >> T >> L >> R;
    if (T == 1) {
      lst.apply(L - 1, R, true);
    } else {
      cout << lst.query(L - 1, R).num_inversion << endl;
    }
  }
}
