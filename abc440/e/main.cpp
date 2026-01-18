#include <atcoder/math>

#include "util/common.h"
int main() {
  s64 n, k, x;
  cin >> n >> k >> x;
  vector<s64> as(n);
  util::cin(as);
  sort(as.begin(), as.end(), greater());

  vector<s64> cnts(n, 0);
  cnts[0] = k;
  s64 val = as.front() * k;
  using elem_t = pair<s64, vector<s64>>;
  priority_queue<elem_t, vector<elem_t>, less<elem_t>> pq;
  set<vector<s64>> s;
  pq.push(make_pair(val, cnts));
  for (s64 i = 0; i < x; ++i) {
    auto [val, cnts] = pq.top();
    cout << val << endl;
    pq.pop();
    for (s64 i = 0; i < n - 1; ++i) {
      s64 nval = val;
      auto ncnts = cnts;
      if (cnts[i]) {
        --ncnts[i];
        ++ncnts[i + 1];
        nval -= as[i];
        nval += as[i + 1];
        if (!s.contains(ncnts)) {
          pq.push(make_pair(nval, ncnts));
          s.emplace(ncnts);
        }
      }
    }
  }
}