#include <atcoder/all>

#include "util/common.h"
int main() {
  s64 N;
  cin >> N;
  string S;
  cin >> S;
  const auto sa = atcoder::suffix_array(S);
  const auto lcp = atcoder::lcp_array(S, sa);

  s64 ans{0};
  ans += N * (N + 1) / 2;
  
}