#include "util/common.h"

int main() {
  using query = tuple<s64, s64, s64>;
  s64 q;
  cin >> q;
  vector<query> queries(q);
  for (auto& [q0, q1, q2] : queries) {
    cin >> q0 >> q1;
    if (q0 == 1) cin >> q2;
  }

  s64 offset_count = 0;
  s64 offset_value = 0;
  vector<s64> sum_counts(1);
  vector<s64> sum_values(1);
  vector<pair<s64, s64>> xcs(1);
  for (auto [q0, q1, q2] : queries) {
    if (q0 == 1) {
      xcs.push_back(make_pair(q2, q1));
      sum_counts.push_back(sum_counts.back() + q1);
      sum_values.push_back(sum_values.back() + q2 * q1);
    } else {
      auto itc =
          lower_bound(sum_counts.begin(), sum_counts.end(), q1 + offset_count);
      const s64 sum_count = *itc;
      const s64 rem_count = sum_count - (q1 + offset_count);

      const auto idx = distance(sum_counts.begin(), itc);
      const s64 sum_value = sum_values[idx];
      auto [x, c] = xcs[idx];
      auto value = sum_value - offset_value - rem_count * x;
      cout << value << endl;

      offset_count += q1;
      offset_value += value;
    }
  }
}