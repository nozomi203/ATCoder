#include "util/common.h"

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<size_t> as(q);
  util::cin(as);
  vector<bool> bs(n + 2, false);

  size_t cnt_b{0};
  for (auto a : as) {
    if (bs[a]) {
      if (bs[a - 1] && bs[a + 1]) {
        ++cnt_b;
      } else if (bs[a - 1] || bs[a + 1]) {
      } else {
        --cnt_b;
      }

    } else {
      if (bs[a - 1] && bs[a + 1]) {
        --cnt_b;
      } else if (bs[a - 1] || bs[a + 1]) {
      } else {
        ++cnt_b;
      }
    }
    bs[a] = !bs[a];
    cout << cnt_b << endl;
  }
}