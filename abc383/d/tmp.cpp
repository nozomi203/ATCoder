#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

size_t pow8(size_t n) { return n * n * n * n * n * n * n * n; }

int main() {
  size_t N;
  cin >> N;
  const size_t sqrt_n = sqrt(N);
  vector<size_t> primes;
  {
    vector<bool> prime(sqrt_n + 1, true);
    for (size_t n = 2; n <= sqrt_n; ++n) {
      if (!prime[n]) continue;
      primes.push_back(n);
      for (size_t k = 2; n * k <= sqrt_n; ++k) prime[n * k] = false;
    }
  }

  size_t ans{0};
  for (auto prime : primes) {
    auto val = pow8(prime);
    if (val > N) break;
    ++ans;
  }

  size_t idx_r{primes.size() - 1};
  for (size_t idx_l{0}; idx_l < primes.size(); ++idx_l) {
    while (idx_l < idx_r && primes[idx_l] * primes[idx_r] > sqrt_n) --idx_r;
    if (idx_l >= idx_r) break;
    ans += (idx_r - idx_l);
  }

  cout << ans << endl;
}
