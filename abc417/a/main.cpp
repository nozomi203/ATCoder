#include "util/common.h"

int main() {
  s64 n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for (s64 i = a; i < n - b; ++i) cout << s[i];
  cout << endl;
}