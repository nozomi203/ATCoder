#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];

  // value_to_indices[i] = list of index j
  unordered_map<s64, vector<s64>> value_to_indices, value_to_indices2;
  for (s64 i = 0; i < N; ++i) {
    value_to_indices[i].push_back(-1);
    value_to_indices[i].push_back(N);
    value_to_indices[A[i]].push_back(i);

    value_to_indices2[i].push_back(-1);
    value_to_indices2[i].push_back(N);
    value_to_indices2[A[i]].push_back(i);
    value_to_indices2[A[i] - 1].push_back(i);
  }

  for (auto& [value, indices] : value_to_indices) {
    sort(indices.begin(), indices.end());
  }
  for (auto& [value, indices] : value_to_indices2) {
    sort(indices.begin(), indices.end());
  }

  const auto get_count = [](const vector<s64>& indices) -> s64 {
    if (indices.empty()) return 0;

    s64 ret{0};
    for (s64 i = 0; i < indices.size() - 1; ++i) {
      ret +=
          (indices[i + 1] - indices[i]) * (indices[i + 1] - indices[i] - 1) / 2;
    }
    return ret;
  };

  s64 ans{0};
  for (s64 i = 1; i <= N; ++i) {
    ans += get_count(value_to_indices[i - 1]);
    ans -= get_count(value_to_indices2[i - 1]);
  }
  cout << ans << endl;
}