#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;

  const auto get = [&](bool ab) -> s64 {
    vector<s64> idxs(2 * n);
    s64 cnta = 0, cntb = 0;
    for (s64 i = 0; i < 2 * n; i++) {
      if (s[i] == 'A') {
        idxs[i] = ab ? cnta * 2 : cnta * 2 + 1;
        cnta++;
      } else {
        idxs[i] = ab ? cntb * 2 + 1 : cntb * 2;
        cntb++;
      }
    }

    s64 ans = 0;
    for (s64 i = 0; i < 2 * n; i++) {
      ans += abs(idxs[i] - i);
    }
    return ans / 2;
  };

  cout << min(get(true), get(false)) << endl;
}