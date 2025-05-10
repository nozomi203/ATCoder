#include <atcoder/math>

#include "util/common.h"
#include "util/sparse_table.h"

int main() {
  s64 n, d;
  cin >> n >> d;
  vector<pair<s64, s64>> xys(n);
  for (s64 i{0}; i < n; ++i) cin >> xys[i].first >> xys[i].second;

  const u64 n1{n - n / 2}, n2{n / 2};
  const auto mb1{atcoder::pow_mod(3, n1, 1000000000)};
  vector<pair<s64, s64>> dxys1(mb1);
  for (u64 b{0}; b < mb1; ++b) {
    s64 xa1{0}, xb1{0}, ya1{0}, yb1{0}, bt(b);
    for (u64 i{0}; i < n1; ++i) {
      switch (bt % 3) {
        case 0:
          break;
        case 1:
          xa1 += xys[i].first;
          ya1 += xys[i].second;
          break;
        case 2:
          xb1 += xys[i].first;
          yb1 += xys[i].second;
          break;
      }
      bt /= 3;
    }
    dxys1[b].first = xb1 - xa1;
    dxys1[b].second = yb1 - ya1;
  }
  sort(dxys1.begin(), dxys1.end(), greater());

  const auto mb2{atcoder::pow_mod(3, n2, 1000000000)};
  vector<pair<s64, s64>> dxys2(mb2);
  for (u64 b{0}; b < mb2; ++b) {
    s64 xa2{0}, xb2{0}, ya2{0}, yb2{0}, bt(b);
    for (u64 i{0}; i < n2; ++i) {
      switch (bt % 3) {
        case 0:
          break;
        case 1:
          xa2 += xys[n1 + i].first;
          ya2 += xys[n1 + i].second;
          break;
        case 2:
          xb2 += xys[n1 + i].first;
          yb2 += xys[n1 + i].second;
          break;
      }
      bt /= 3;
    }
    dxys2[b].first = xb2 - xa2;
    dxys2[b].second = yb2 - ya2;
  }
  sort(dxys2.begin(), dxys2.end());

  s64 ans{0};
  deque<s64> dq;
  s64 idx2{0};
  for (u64 b1{0}; b1 < mb1; ++b1) {
    const auto& [dx1, dy1] = dxys1[b1];
    while (idx2 < dxys2.size() && dxys2[idx2].first <= d - dx1) {
      while (!dq.empty() && dxys2[dq.back()].second < dxys2[idx2].second)
        dq.pop_back();
      dq.push_back(idx2++);
    }
    while (!dq.empty() && dxys2[dq.front()].first < -d - dx1) dq.pop_front();
    if (!dq.empty()) ans = max(ans, dy1 + dxys2[dq.front()].second);
  }
  cout << ans << endl;
}