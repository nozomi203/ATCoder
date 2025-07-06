#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<tuple<s64, s64, s64, s64>> pqrbs(n);
  util::cin(pqrbs);

  s64 root = -1;
  {
    vector<s64> refcnts(n);
    for (auto& [p, q, r, b] : pqrbs) {
      auto gcd = std::gcd(p, q);
      p /= gcd;
      q /= gcd;

      --r;
      --b;
      if (r >= 0) refcnts[r]++;
      if (b >= 0) refcnts[b]++;
    }
    auto it = std::find(refcnts.begin(), refcnts.end(), 0);
    root = distance(refcnts.begin(), it);
  }

  stack<s64> s;
  vector<bool> opened(n);
  vector<pair<s64, s64>> ws(n);
  s.push(root);
  while (!s.empty()) {
    auto idx = s.top();
    auto [p, q, r, b] = pqrbs[idx];
    if (opened[idx]) {
      if (r < 0) {
        if (b < 0) {
          ws[idx].first = q;
          ws[idx].second = p;
        } else {
          const auto wb = ws[b].first + ws[b].second;
          const auto gcd = std::gcd(q * wb, p);
          const auto mul = p / gcd;
          ws[idx].first = q * wb / gcd;
          ws[idx].second = wb * mul;
        }
      } else {
        if (b < 0) {
          const auto wr = ws[r].first + ws[r].second;
          const auto gcd = std::gcd(p * wr, q);
          const auto mul = q / gcd;
          ws[idx].first = wr * mul;
          ws[idx].second = p * wr / gcd;
        } else {
          const auto wr = ws[r].first + ws[r].second;
          const auto wb = ws[b].first + ws[b].second;
          const auto gcd = std::gcd(p * wr, q * wb);
          ws[idx].first = wr * wb * q / gcd;
          ws[idx].second = wb * wr * p / gcd;
        }
      }
      s.pop();
    } else {
      opened[idx] = true;
      if (r >= 0) s.push(r);
      if (b >= 0) s.push(b);
    }
  }

  cout << ws[root].first + ws[root].second << endl;
}