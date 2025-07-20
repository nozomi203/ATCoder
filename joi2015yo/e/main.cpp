#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> ss(h);
  util::cin(ss);

  const auto ctoi = [](char i) -> size_t { return i - '0'; };
  const auto check = [&](s64 ci, s64 cj) -> bool {
    if (ss[ci][cj] == '.') return false;
    s64 cnt = 0;
    for (s64 i = ci - 1; i <= ci + 1; ++i) {
      for (s64 j = cj - 1; j <= cj + 1; ++j) {
        if (ss[i][j] == '.') ++cnt;
      }
    }

    return cnt >= ctoi(ss[ci][cj]);
  };

  vector<vector<bool>> opened(h, vector<bool>(w));
  vector<pair<size_t, size_t>> ps;
  for (size_t i = 1; i < h - 1; ++i) {
    for (size_t j = 1; j < w - 1; ++j) {
      if (check(i, j)) {
        ps.push_back(make_pair(i, j));
        opened[i][j] = true;
      }
    }
  }

  size_t cnt = 0;
  size_t wave = 0;
  while (cnt < ps.size()) {
    size_t begin = cnt;
    cnt = ps.size();
    for (size_t idx = begin; idx < cnt; ++idx) {
      const auto [pi, pj] = ps[idx];
      ss[pi][pj] = '.';
    }

    for (size_t idx = begin; idx < cnt; ++idx) {
      const auto [pi, pj] = ps[idx];
      for (size_t i = pi - 1; i <= pi + 1; ++i) {
        for (size_t j = pj - 1; j <= pj + 1; ++j) {
          if (check(i, j) && !opened[i][j]) {
            ps.push_back(make_pair(i, j));
            opened[i][j] = true;
          }
        }
      }
    }

    ++wave;
  }

  cout << wave << endl;

  /*各マスの更地の数を数え、崩れるものをstackに詰める*/
  /*ある波が去ったとき、次の波で崩れる可能性があるのは今の波で崩れたマスの周囲にあるマス*/
}