#include "util/common.h"

int main() {
  s64 N, S;
  cin >> N >> S;
  vector<s64> values(N + 1);
  unordered_set<s64> sum_from0, sum_fromN;
  {
    s64 sum{0};
    for (s64 n = 1; n <= N; ++n) {
      sum_from0.emplace(sum);
      cin >> values[n];
      sum += values[n];
    }
    S = S % sum;
    for (s64 n = 1; n <= N; ++n) {
      sum -= values[n];
      sum_fromN.emplace(sum);
    }
  }

  // しゃくとり
  s64 idx_r = 1;
  s64 sum = values[1];
  for (s64 idx_l = 1; idx_l <= N; ++idx_l) {
    if (idx_r > N) {
      break;
    }
    while (sum < S) {
      ++idx_r;
      if (idx_r > N) {
        break;
      }
      sum += values[idx_r];
    }
    if (sum == S) {
      cout << "Yes" << endl;
      return 0;
    }
    sum -= values[idx_l];
  }

  for (s64 sum : sum_from0) {
    s64 rem = S - sum;
    if (sum_fromN.find(rem) != sum_fromN.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}