#include "util/common.h"

int main() {
  size_t t;
  cin >> t;
  vector<string> cases(t);
  for (size_t i{0}; i < t; ++i) {
    size_t n;
    cin >> n;
    cin >> cases[i];
  }

  for (const auto& s : cases) {
    vector<int64_t> cnt_zero(s.size() + 1), cnt_one(s.size() + 1),
        diff_cnt(s.size() + 1), diff_cnt_max(s.size() + 1);
    for (size_t i{0}; i < s.size(); ++i) {
      cnt_zero[i + 1] = cnt_zero[i];
      cnt_one[i + 1] = cnt_one[i];

      if (s[i] == '0') {
        ++cnt_zero[i + 1];
      } else {
        ++cnt_one[i + 1];
      }
      diff_cnt[i + 1] = cnt_zero[i + 1] - cnt_one[i + 1];
      diff_cnt_max[i + 1] = max(diff_cnt_max[i], diff_cnt[i + 1]);
    }
    int64_t cnt_min{numeric_limits<int64_t>::max()};
    for (size_t r{1}; r <= s.size() + 1; ++r) {
      cnt_min = min(cnt_min,
                    cnt_one[s.size()] + diff_cnt[r - 1] - diff_cnt_max[r - 1]);
    }
    cout << cnt_min << endl;
  }
}