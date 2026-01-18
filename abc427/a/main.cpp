#include "util/common.h"

int main() {
  string s;
  cin >> s;
  size_t n = s.size();
  cout << s.substr(0, n / 2);
  cout << s.substr(n / 2 + 1, n / 2);
  cout << endl;
}