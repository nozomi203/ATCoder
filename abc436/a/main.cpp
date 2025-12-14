#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  string s;
  cin >> s;
  s = string(n - s.size(), 'o').append(s);
  cout << s << endl;
}