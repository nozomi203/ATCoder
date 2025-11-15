#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  for (s64 i = 1; i <= n; ++i)
    cout << (i <= m ? "OK" : "Too Many Requests") << endl;
}