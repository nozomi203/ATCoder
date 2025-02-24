#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<map<char, vector<s64>>> f(N), b(N);
  struct work {
    s64 idx_l;
    s64 idx_r;
    s64 len;
  };
  queue<work> works;
  for (s64 i = 0; i < N; ++i) {
    works.push(work{i, i, 0});
  }
  for (s64 i = 0; i < N; ++i) {
    string str;
    cin >> str;
    for (s64 j = 0; j < N; ++j) {
      if (str[j] == '-') continue;
      f[i][str[j]].push_back(j);
      b[j][str[j]].push_back(i);
      works.push(work{i, j, 1});
    }
  }

  vector<vector<s64>> answers(N, vector<s64>(N, -1));
  while (!works.empty()) {
    const auto w = works.front();
    works.pop();
    if (answers[w.idx_l][w.idx_r] < 0 || answers[w.idx_l][w.idx_r] > w.len) {
      answers[w.idx_l][w.idx_r] = w.len;
      for (char c = 'a'; c <= 'z'; ++c) {
        for (auto idx_l : b[w.idx_l][c]) {
          for (auto idx_r : f[w.idx_r][c]) {
            works.push(work{idx_l, idx_r, w.len + 2});
          }
        }
      }
    }
  }

  for (s64 i = 0; i < N; ++i) {
    for (s64 j = 0; j < N; ++j) {
      cout << answers[i][j];
      if (j != N - 1) cout << " ";
    }
    cout << endl;
  }
}