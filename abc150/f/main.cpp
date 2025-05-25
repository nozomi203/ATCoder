#include "util/common.h"
#include "util/rolling_hash.h"

int main() {
  u64 n;
  cin >> n;
  vector<u64> a(n), b(n);
  for (size_t i{0}; i < n; ++i) cin >> a[i];
  for (size_t i{0}; i < n; ++i) cin >> b[i];
  vector<u64> a2(n), b2(n);
  for (size_t i{0}; i < n; ++i) {
    a2[i] = a[i] ^ a[(i + 1) % n];
    b2[i] = b[i] ^ b[(i + 1) % n];
  }
  vector<u64> v(3 * n);
  for (size_t i{0}; i < n; ++i) {
    v[i] = v[i + n] = a2[i];
    v[i + 2 * n] = b2[i];
  }
  util::rolling_hash rh(v);
  bool found{false};
  for (size_t k{0}; k < n; ++k) {
    if (rh.get_hash(k, k + n) == rh.get_hash(2 * n, 3 * n)) {
      found = true;
      cout << k << " " << (a[k] ^ b[0]) << endl;
    }
  }
  if (!found) cout << endl;
}
