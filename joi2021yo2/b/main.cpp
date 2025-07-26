#include "util/common.h"

/*
ABC 0 * 1 + 1 * 3 + 2 * 9
BAC 1 * 1 + 0 * 3 + 2 * 9
CBA 2 * 1 + 1 * 3 + 0 * 9
*/

size_t toidx(char c) { return c - 'A'; }

size_t pow(size_t i, size_t p) {
  if (p == 0) return 1;
  return i * pow(i, p - 1);
}

size_t toidx(const string& s) {
  size_t ret = 0;
  size_t pow3 = 1;
  for (size_t i = 0; i < s.size(); ++i) {
    ret += pow3 * toidx(s[i]);
    pow3 *= 3;
  }
  return ret;
}

size_t revidx(size_t idx, size_t n) {
  size_t p = pow(3, n - 1);
  size_t ret = 0;
  for (size_t i = 0; i < n; ++i) {
    ret += p * (idx % 3);
    idx /= 3;
    p /= 3;
  }
  return ret;
}

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<string> ss(q);
  util::cin(ss);

  queue<size_t> que;
  constexpr auto inf = numeric_limits<size_t>::max();
  const size_t sz = pow(3, n);
  vector<size_t> dists(sz, inf);
  for (size_t acnt = 0; acnt <= n; ++acnt) {
    for (size_t bcnt = 0; bcnt <= n - acnt; ++bcnt) {
      const size_t ccnt = n - (acnt + bcnt);
      string s;
      s.reserve(n);
      for (size_t i = 0; i < acnt; ++i) s.push_back('A');
      for (size_t i = 0; i < bcnt; ++i) s.push_back('B');
      for (size_t i = 0; i < ccnt; ++i) s.push_back('C');
      const auto idx = toidx(s);
      dists[idx] = 0;
      que.push(idx);
    }
  }

  while (!que.empty()) {
    size_t idx = que.front();
    const size_t dist = dists[idx];
    que.pop();

    size_t idxl = 0;
    size_t idxu = idx;
    size_t pow = 3;
    for (size_t i = 0; i < n; ++i) {
      const size_t b = idxu % 3;
      idxu /= 3;
      idxl = idxl * 3 + b;
      idx = idxu * pow + idxl;

      pow *= 3;

      if (dists[idx] == inf) {
        dists[idx] = dist + 1;
        que.push(idx);
      }
    }
  }

  for (auto& s : ss) {
    cout << dists[toidx(s)] << endl;
  }
}