#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  set<s64> s;
  for (s64 i = 0; i < M; ++i) {
    s64 A;
    cin >> A;
    s.emplace(A);
  }
  cout << N - s.size() << endl;
  s64 cnt{0};
  for (s64 i = 1; i <= N; ++i) {
    if (s.contains(i)) continue;
    cout << i;
    cnt++;
    if (cnt < N - s.size()) {
      cout << " ";
    }
  }
  cout << endl;
}