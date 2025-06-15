#include "util/common.h"
#include "util/value_compressor.h"
int main() {
  size_t n;
  cin >> n;
  size_t a, b;
  cin >> a >> b;
  vector<tuple<s32, s32, s32, s32>> pqrss(n);
  util::cin(pqrss);

  map<pair<s32, s32>, s32> cnts;
  for (auto& [p, q, r, s] : pqrss) {
    for (s32 i{p}; i <= r; ++i) {
      for (s32 j{q}; j <= s; ++j) {
        ++cnts[{i, j}];
      }
    }
  }

  s32 max_overlap{0};
  for (const auto& [pos, overlap] : cnts) {
    max_overlap = max(max_overlap, overlap);
  }

  s32 ans{0};
  for (const auto& [pos, overlap] : cnts) {
    if (overlap == max_overlap) ++ans;
  }
  cout << max_overlap << endl;
  cout << ans << endl;
}