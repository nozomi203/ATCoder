#include "util/binary_search.h"
#include "util/common.h"
#include "util/segment_tree.h"

int main() {
  size_t N;
  cin >> N;

  using S = size_t;
  constexpr S kSIdentity = 0;
  constexpr auto kOpFunc = [](S l, S r) -> S { return l + r; };
  util::segment_tree<S, kSIdentity, kOpFunc> st(N + 1, 1);
  st.apply(0, 0);

  vector<size_t> P(N + 1), A_(N + 1), A(N + 1);
  for (size_t i = 1; i <= N; ++i) {
    cin >> P[i];
    P[i];
    A_[i] = i;
  }
  for (size_t i = N; i >= 1; --i) {
    auto [ok, ng] = util::binary_search<s64>(0, N, [&](auto value) -> bool {
      return st.query(0, value + 1) < P[i];
    });
    st.apply(ng, 0);
    A[A_[ng]] = i;
  }

  for (size_t i = 1; i <= N; ++i) {
    cout << A[i];
    if (i < N) cout << " ";
  }
  cout << endl;
}