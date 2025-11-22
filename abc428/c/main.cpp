#include "util/common.h"

int main() {
  s64 q;
  cin >> q;

  vector<s64> sums;
  vector<s64> num_invalids;

  for (s64 i = 0; i < q; ++i) {
    s64 a;
    cin >> a;
    if (a == 1) {
      char c;
      cin >> c;
      const s64 add1 = c == '(' ? 1 : -1;
      sums.push_back(sums.empty() ? add1 : sums.back() + add1);
      const s64 add2 = sums.back() < 0 ? 1 : 0;
      num_invalids.push_back(num_invalids.empty() ? add2
                                                  : num_invalids.back() + add2);
    } else {
      sums.pop_back();
      num_invalids.pop_back();
    }

    const bool b =
        sums.empty() || (sums.back() == 0 && num_invalids.back() == 0);
    cout << (b ? "Yes" : "No") << endl;
  }
}