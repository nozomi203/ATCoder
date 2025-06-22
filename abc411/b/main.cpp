#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  vector<size_t> d(n - 1);
  util::cin(d);
  for (size_t i{0}; i < n - 2; ++i) {
    d[i + 1] += d[i];
  }

  for (size_t i{0}; i < n - 1; ++i) {
    for (size_t j{i + 1}; j < n; ++j) {
      cout << d[j - 1] - (i ? d[i - 1] : 0);
      if (j < n - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}