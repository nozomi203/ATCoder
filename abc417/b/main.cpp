#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> as(n), bs(m);
  util::cin(as);
  util::cin(bs);
  map<s64, s64> map;
  for (auto a : as) {
    ++map[a];
  }
  for (auto b : bs) {
    --map[b];
  }

  bool any = false;
  for (auto [k, v] : map) {
    if (v >= 0) {
      any = true;
      for (s64 i = 0; i < v; ++i) cout << k << " ";
    }
  }
  if (any) cout << endl;
}