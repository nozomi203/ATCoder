#include "util/common.h"

/*
B
*/

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<s64> as(n);
  util::cin(as);
  vector<s64> ks(q);
  util::cin(ks);

  vector<s64> as_sorted = as;
  sort(as_sorted.begin(), as_sorted.end());
}