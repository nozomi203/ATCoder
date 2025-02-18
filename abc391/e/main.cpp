#include "util/common.h"
#include "util/math.h"

int main() {
  u32 N;
  string A;
  cin >> N;
  cin >> A;
  const size_t powi_3_N = util::powi(3, N);
  const size_t bit_cnt = (powi_3_N * 3 - 1) / 2;
  vector<u32> bits(bit_cnt + 1, 0);
  for (u32 i = 0; i < powi_3_N; ++i) {
    const auto idx = bit_cnt - powi_3_N + i + 1;
    bits[idx] = A[i] == '1' ? 1 : 0;
  }
  for (u32 i = bit_cnt - powi_3_N; i > 0; --i) {
    u32 sum = bits[i * 3 - 1] + bits[i * 3] + bits[i * 3 + 1];
    bits[i] = sum > 1 ? 1 : 0;
  }

  const auto get_min_change = [&](const auto self, u32 idx, u32 depth) -> u32 {
    if (depth == N - 1) {
      u32 change_cnt{0};
      if (bits[idx * 3 - 1] == bits[idx]) ++change_cnt;
      if (bits[idx * 3 + 0] == bits[idx]) ++change_cnt;
      if (bits[idx * 3 + 1] == bits[idx]) ++change_cnt;
      return change_cnt - 1;
    }

    vector<u32> cand;
    if (bits[idx * 3 - 1] == bits[idx])
      cand.push_back(self(self, idx * 3 - 1, depth + 1));
    if (bits[idx * 3 + 0] == bits[idx])
      cand.push_back(self(self, idx * 3 + 0, depth + 1));
    if (bits[idx * 3 + 1] == bits[idx])
      cand.push_back(self(self, idx * 3 + 1, depth + 1));
    sort(cand.begin(), cand.end());

    u32 ret{0};
    for (size_t idx = 0; idx < cand.size() - 1; ++idx) ret += cand[idx];

    return ret;
  };

  cout << get_min_change(get_min_change, 1, 0) << endl;
}