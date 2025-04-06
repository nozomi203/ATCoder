#include "util/common.h"
#include "util/math.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xys(n);
  for (s64 i{0}; i < n; ++i) cin >> xys[i].first >> xys[i].second;

  vector<s64> idxs(n);
  iota(idxs.begin(), idxs.end(), 0);

  const auto count = util::fact(n);
  double sum{0.0};
  do {
    for (size_t i{0}; i < n - 1; ++i) {
      auto to = idxs[i + 1];
      auto from = idxs[i];
      auto dx = xys[to].first - xys[from].first;
      auto dy = xys[to].second - xys[from].second;
      sum += sqrt(dx * dx + dy * dy);
    }
  } while (next_permutation(idxs.begin(), idxs.end()));

  cout << fixed << setprecision(15) << sum / count << endl;
}