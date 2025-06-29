#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);
  {
    vector<s64> tmp;
    for (auto a : as) {
      if (tmp.empty() || tmp.back() != a) tmp.push_back(a);
    }
    swap(tmp, as);
  }

  map<s64, vector<s64>> mis;
  for (s64 i = 0; i < as.size(); ++i) {
    if (as[i]) mis[as[i]].push_back(i);
  }

  s64 cnt = 0;
  {
    bool b = false;
    for (auto a : as) {
      if (a) {
        if (!b) {
          b = true;
          ++cnt;
        }
      } else {
        b = false;
      }
    }
  }
  s64 cnt_max = cnt;
  for (const auto& [a, idxs] : mis) {
    for (auto idx : idxs) {
      if (idx > 0 && idx < as.size() - 1 && as[idx - 1] > as[idx] &&
          as[idx] < as[idx + 1]) {
        ++cnt;
      }
      if ((idx == 0 || as[idx - 1] < as[idx]) &&
          (idx == as.size() - 1 || as[idx] > as[idx + 1])) {
        --cnt;
      }
    }
    cnt_max = max(cnt_max, cnt);
  }

  cout << cnt_max << endl;
}