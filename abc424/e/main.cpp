#include "util/common.h"

/*
asを降順にならべ先頭から見ていく
as[i]が最大値になるまで選択される棒の数を考える
*/

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, s64, vector<s64>>> cases(t);
  for (auto& [n, k, x, as] : cases) {
    cin >> n >> k >> x;
    as.resize(n);
    util::cin(as);
  }

  for (const auto& [n, k, x, as] : cases) {
  }
}