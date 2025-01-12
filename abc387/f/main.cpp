#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  vector<s64> A(N);
  vector<vector<s64>> childs(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> --A[i];
    childs[A[i]].push_back(i);
  }
}