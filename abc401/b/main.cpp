#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  s64 cnt{0};
  bool login{false};
  for (s64 i{0}; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "login") {
      login = true;
    } else if (s == "logout") {
      login = false;
    } else if (s == "public") {
    } else {
      if (!login) ++cnt;
    }
  }
  cout << cnt << endl;
}