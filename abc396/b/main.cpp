#include "util/common.h"

int main() {
  s64 q;
  cin >> q;
  stack<s64> s;
  for (s64 i{0}; i < q; ++i) {
    s64 query;
    cin >> query;

    if (query == 1) {
      s64 x;
      cin >> x;
      s.push(x);
    } else {
      if (s.empty()) {
        cout << 0 << endl;
      } else {
        cout << s.top() << endl;
        s.pop();
      }
    }
  }
}