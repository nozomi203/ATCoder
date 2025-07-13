
#include "util/common.h"

int main() {
  for (size_t n = 3; n <= 100; ++n) {
    const string fname_in = format("tests/sample_generated_{}.in", n);
    const string fname_out = format("tests/sample_generated_{}.out", n);

    ofstream fin(fname_in), fout(fname_out);
    fin << n << endl;
    size_t ans = 0;
    for (size_t a = 1; a <= n; ++a) {
      for (size_t b = 1; b <= n; ++b) {
        for (size_t c = 1; c <= n; ++c) {
          if (a == b || b == c || c == a) continue;
          if (a % b == c) ++ans;
        }
      }
    }
    fout << ans << endl;
  }
}