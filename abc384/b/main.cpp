#include "util/common.h"

int main() {
  s64 N, R;
  cin >> N >> R;
  for (s64 n = 0; n < N; ++n) {
    s64 D, A;
    cin >> D >> A;
    const s64 minRate = D == 1 ? 1600 : 1200;
    const s64 maxRate = D == 1 ? 2799 : 2399;
    if (minRate <= R && R <= maxRate) {
      R += A;
    }
  }
  cout << R << endl;
}