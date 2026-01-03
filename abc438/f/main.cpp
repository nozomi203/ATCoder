#include <atcoder/dsu>

#include "util/common.h"

/*
f(i,j) = x となる(i,j)(i <= j)の数g(x)を求める
番号の小さい頂点から見ていく。
頂点xについて考えるとき、g(x)にカウントされる(i,j)のペアは、頂点[0...x-1]をすべてパスに含み、xは含まない
この頂点[0...x-1]を含むパスは両端が決まるため、その両端から派生するパスの数を数えればいい。
*/

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> uvs(n - 1);
  util::cin(uvs);
  vector<vector<s64>> g(n + 1);
  for (auto [u, v] : uvs) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<s64> ps(n + 1);
  {
    ps[n] = -1;
    stack<s64> s;
    s.push(n);
    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      for (auto nxt : g[cur]) {
        if (nxt == ps[cur]) continue;
        ps[nxt] = cur;
        s.push(nxt);
      }
    }
  }
  vector<s64> nums(n + 1);
  {
    vector<s64> bs(n + 1);
    stack<s64> s;
    s.push(n);
    while (!s.empty()) {
      auto cur = s.top();
      if (bs[cur]) {
        nums[cur] = 1;
        for (auto nxt : g[cur]) {
          if (nxt == ps[cur]) continue;
          nums[cur] += nums[nxt];
        }
      } else {
        bs[cur] = true;
        for (auto nxt : g[cur]) {
          if (nxt == ps[cur]) continue;
          s.push(nxt);
        }
      }
    }
  }
}