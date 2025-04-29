#include <bits/stdc++.h>

#include <atcoder/math>
#include <atcoder/modint>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
  s64 n;
  cin >> n;
  struct edge {
    size_t edge_idx;
    s64 from_idx;
    s64 to_idx;
    s64 cnt;
  };
  struct node {
    vector<edge> edges;
  };

  vector<node> g(n);
  for (s64 i{0}; i < n - 1; ++i) {
    s64 a, b;
    cin >> a >> b;
    g[a - 1].edges.push_back(edge{g[a - 1].edges.size(), a - 1, b - 1, 0});
    g[b - 1].edges.push_back(edge{g[b - 1].edges.size(), b - 1, a - 1, 0});
  }

  {
    vector<s64> open(n);
    stack<edge*> s;
    for (auto& e : g[0].edges) {
      s.push(&e);
    }
    while (!s.empty()) {
      edge& e = *s.top();
      if (open[e.to_idx]) {
        e.cnt += 1;
        for (auto& ce : g[e.to_idx].edges)
          if (ce.to_idx != e.from_idx) e.cnt += ce.cnt;
        s.pop();
      } else {
        open[e.to_idx] = true;
        for (auto& ce : g[e.to_idx].edges)
          if (ce.to_idx != e.from_idx) s.push(&ce);
      }
    }
  }

  {
    stack<edge*> s;
    for (auto& e : g[0].edges) {
      s.push(&e);
    }
    while (!s.empty()) {
      edge& e = *s.top();
      s.pop();
      for (auto& ce : g[e.to_idx].edges) {
        if (ce.to_idx != e.from_idx) {
          s.push(&ce);
        } else {
          ce.cnt = n - e.cnt;
        }
      }
    }
  }

  using mint = atcoder::modint1000000007;

  mint a(0), b(0), c(0), d(0);
  a = n * atcoder::pow_mod(2, n - 1, mint::mod());
  for (s64 i{0}; i < n; ++i) {
    for (const auto& ce : g[i].edges) {
      b += atcoder::pow_mod(2, ce.cnt, mint::mod());
    }
  }
  c = n - 2;
  d = atcoder::pow_mod(2, n, mint::mod());

  cout << ((a - b + c) / d).val() << endl;
}