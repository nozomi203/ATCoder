#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> P(N + 1), Q(N + 1), R(N + 1);
  for (s64 i = 1; i <= N; ++i) cin >> P[i];
  for (s64 i = 1; i <= N; ++i) {
    cin >> Q[i];
    R[Q[i]] = i;
  }
  for (s64 i = 1; i <= N; ++i) {
    cout << Q[P[R[i]]];
    if (i < N) cout << " ";
  }
  cout << endl;
}