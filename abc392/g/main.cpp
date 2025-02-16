#include <atcoder/all>

#include "util/common.h"

int main() {
  size_t N;
  cin >> N;
  vector<size_t> a(1000001, 0);
  for (size_t i = 0; i < N; ++i) {
    size_t S;
    cin >> S;
    a[S] = 1;
  }
  const auto c = atcoder::convolution(a, a);

  size_t ans{0};
  for (size_t i = 1; i < 1000001; ++i) {
    if (a[i]) {
      ans += (c[2 * i] - 1) / 2;
    }
  }
  cout << ans << endl;
}