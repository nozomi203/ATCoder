#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  vector<pair<s64, s64>> s;
  for (s64 i = 0; i < n; ++i) {
    if (s.empty()) {
      s.push_back(pair<s64, s64>(as[i], 1));
    } else {
      auto [num, cnt] = s.back();
      if (num == as[i]) {
        s.push_back(pair<s64, s64>(as[i], cnt + 1));
      } else {
        s.push_back(pair<s64, s64>(as[i], 1));
      }
    }
    if (s.back().second == 4) {
      s.pop_back();
      s.pop_back();
      s.pop_back();
      s.pop_back();
    }
  }

  cout << s.size() << endl;
}