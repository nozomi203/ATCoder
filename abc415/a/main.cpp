#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);
  s64 x;
  cin >> x;

  cout << (find(as.begin(), as.end(), x) == as.end() ? "No" : "Yes") << endl;
}