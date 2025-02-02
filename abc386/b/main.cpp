#include "util/common.h"

int main() {
  string S;
  cin >> S;
  s64 ans{0};
  s64 cnt{0};
  while (cnt < S.size()) {
    if (cnt < S.size() - 1 && S[cnt] == '0' && S[cnt + 1] == '0') {
      cnt += 2;
      ++ans;
    } else {
      ++cnt;
      ++ans;
    }
  }

  cout << ans << endl;
}