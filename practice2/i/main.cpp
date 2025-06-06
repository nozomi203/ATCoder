#include <atcoder/all>

#include "util/common.h"

int main() {
  string S;
  cin >> S;
  const auto sa = atcoder::suffix_array(S);
  const auto lcp = atcoder::lcp_array(S, sa);

  s64 ans{S.size() * (S.size() + 1) / 2};
  for (auto v : lcp) {
    ans -= v;
  }

  cout << ans << endl;
}