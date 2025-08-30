#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<string> ss(n);
  util::cin(ss);
  s64 x;
  string y;
  cin >> x >> y;
  cout << (ss[x - 1] == y ? "Yes" : "No") << endl;
}