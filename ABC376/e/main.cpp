#include "util/common.h"

int main() {
  s64 T;
  cin >> T;
  struct test {
    s64 n;
    s64 k;
    vector<pair<s64, s64>> abs;
  };
  vector<test> tests(T);
  for (s64 i{0}; i < T; ++i) {
    s64 N, K;
    cin >> N >> K;
    tests[i].n = N;
    tests[i].k = K;
    tests[i].abs.resize(N);
    for (s64 j{0}; j < N; ++j) cin >> tests[i].abs[j].first;
    for (s64 j{0}; j < N; ++j) cin >> tests[i].abs[j].second;
    sort(tests[i].abs.begin(), tests[i].abs.end());
  }

  for (const auto& test : tests) {
    s64 sumb{0};
    s64 ans{numeric_limits<s64>::max()};
    priority_queue<s64> pq;
    for (s64 i{0}; i < test.abs.size(); ++i) {
      if (pq.size() == test.k - 1) {
        ans = min(ans, test.abs[i].first * (test.abs[i].second + sumb));
      }
      pq.push(test.abs[i].second);
      sumb += test.abs[i].second;
      if (pq.size() == test.k) {
        const auto top = pq.top();
        pq.pop();
        sumb -= top;
      }
    }

    cout << ans << endl;
  }
}