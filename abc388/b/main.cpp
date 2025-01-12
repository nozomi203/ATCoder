#include "util/common.h"

int main() {
  s64 N, D;
  cin >> N >> D;
  vector<s64> thicks(N), lengths(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> thicks[i] >> lengths[i];
  }

  for (s64 k = 1; k <= D; ++k) {
    s64 weight_max{0};
    for (s64 i = 0; i < N; ++i) {
      weight_max = max(weight_max, thicks[i] * (lengths[i] + k));
    }
    cout << weight_max << endl;
  }
}