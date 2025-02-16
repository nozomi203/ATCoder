#include "util/common.h"

int main() {
  s64 N, P, Q;
  cin >> N >> P >> Q;
  vector<vector<s64>> A(N, vector<s64>(N));
  for (s64 i = 0; i < N; ++i) {
    for (s64 j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
}