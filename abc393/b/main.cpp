#include "util/common.h"

int main() {
  string S;
  cin >> S;
  size_t ans{0};
  for (size_t i = 0; i < S.size(); ++i) {
    if (S[i] != 'A') continue;
    for (size_t w = 1; w < S.size(); ++w) {
      if (i + 2 * w >= S.size()) continue;
      if (S[i + w] == 'B' && S[i + 2 * w] == 'C') ++ans;
    }
  }

  cout << ans << endl;
}