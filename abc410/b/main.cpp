#include "util/common.h"

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<size_t> xs(q);
  for (size_t i{0}; i < q; ++i) cin >> xs[i];
  vector<size_t> cnts(n);
  vector<size_t> answers;
  for (auto x : xs) {
    if (x > 0) {
      answers.push_back(x - 1);
      ++cnts[x - 1];
    } else {
      size_t min_value{numeric_limits<size_t>::max()},
          min_idx{numeric_limits<size_t>::max()};
      for (size_t i{0}; i < n; ++i) {
        if (cnts[i] < min_value) {
          min_value = cnts[i];
          min_idx = i;
        } else if (cnts[i] == min_value) {
          if (i < min_idx) {
            min_idx = i;
          }
        }
      }
      cnts[min_idx]++;
      answers.push_back(min_idx);
    }
  }

  for (auto ans : answers) {
    cout << ans + 1 << " ";
  }
  cout << endl;
}
