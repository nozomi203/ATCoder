#include "util/common.h"
#include "util/run_length_encoding.h"

size_t del_cnt(const vector<pair<size_t, size_t>>& rles, s64 l, s64 r) {
  size_t del{0};
  while (l >= 0 && r < rles.size() && rles[l].first == rles[r].first &&
         rles[l].second + rles[r].second >= 4) {
    del += rles[l].second + rles[r].second;
    --l;
    ++r;
  }
  return del;
}

int main() {
  size_t n;
  cin >> n;
  vector<size_t> cs(n);
  util::cin(cs);

  if (n < 4) {
    cout << n << endl;
    return 0;
  }

  size_t del_max{0};
  auto rles = util::run_length_encoding::encode(cs);
  for (s64 i{0}; i < rles.size(); ++i) {
    auto& [c, count] = rles[i];
    if (i == 0) {
      if (rles[i + 1].second == 3) {
        del_max = max<size_t>(del_max, 4ULL);
      }
    } else if (i == rles.size() - 1) {
      if (rles[i - 1].second == 3) {
        del_max = max<size_t>(del_max, 4ULL);
      }
    } else {
      if (count == 1) {
        if (rles[i - 1].first == rles[i + 1].first &&
            rles[i - 1].second + rles[i + 1].second >= 3) {
          size_t del{1 + rles[i - 1].second + rles[i + 1].second};
          del_max = max<size_t>(del_max, del + del_cnt(rles, i - 2, i + 2));
        } else {
          if (rles[i - 1].second == 3) {
            del_max = max<size_t>(del_max, 4ULL + del_cnt(rles, i - 2, i + 1));
          }
          if (rles[i + 1].second == 3) {
            del_max = max<size_t>(del_max, 4ULL + del_cnt(rles, i - 1, i + 2));
          }
        }
      } else {
        if (rles[i - 1].second == 3) {
          size_t del{4ULL};
          if (i - 2 >= 0 && rles[i - 2].first == c &&
              rles[i - 2].second + count - 1 >= 4ULL) {
            del += rles[i - 2].second + count - 1;
            del += del_cnt(rles, i - 3, i + 1);
          }
          del_max = max<size_t>(del_max, del);
        }
        if (rles[i + 1].second == 3) {
          size_t del{4ULL};
          if (i + 2 < rles.size() && rles[i + 2].first == c &&
              rles[i + 2].second + count - 1 >= 4ULL) {
            del += rles[i + 2].second + count - 1;
            del += del_cnt(rles, i - 1, i + 3);
          }
          del_max = max<size_t>(del_max, del);
        }
      }
    }
  }

  cout << n - del_max << endl;
}