#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n);
  util::cin(as);
  auto acum = accumulate(as.begin(), as.end(), 0);
  cout << (acum <= m ? "Yes" : "No") << endl;
}