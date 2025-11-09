#include "util/common.h"

int main() {
  s64 x, n;
  cin >> x >> n;
  vector<s64> ws(n);
  util::cin(ws);
  s64 q;
  cin >> q;
  vector<s64> ps(q);
  util::cin(ps);

  vector<bool> has(n);

  for (auto p : ps) {
    if (has[p - 1]) {
      x -= ws[p - 1];
    } else {
      x += ws[p - 1];
    }
    has[p - 1] = !has[p - 1];
    cout << x << endl;
  }
}