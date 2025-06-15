#include "util/common.h"

int main() {
  size_t n, q;
  cin >> n >> q;
  vector<tuple<size_t, size_t, size_t>> queries(q);
  for (auto& [a, b, c] : queries) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
    } else if (a == 2) {
      cin >> b;
    } else {
      cin >> b;
    }
  }

  size_t head{0};
  vector<size_t> as(n);
  iota(as.begin(), as.end(), 1);
  for (auto [a, b, c] : queries) {
    if (a == 1) {
      as[(head + b - 1) % n] = c;
    } else if (a == 2) {
      cout << as[(head + b - 1) % n] << endl;
    } else {
      head = (head + b) % n;
    }
  }
}
