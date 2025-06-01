#include "util/common.h"

int main() {
  size_t n;
  cin >> n;
  set<size_t> m;
  for (size_t i{0}; i < n; ++i) {
    size_t a;
    cin >> a;
    m.emplace(a);
  }
  cout << m.size() << endl;
  for (auto a : m) {
    cout << a << " ";
  }
  if (!m.empty()) cout << endl;
}