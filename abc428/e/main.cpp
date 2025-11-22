#include "util/common.h"
#include "util/rerooting_dp.h"

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> abs(n - 1);
  util::cin(abs);

  vector<vector<s64>> g(n);
  for (auto [a, b] : abs) {
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  vector<s64> inputs(n);
  iota(inputs.begin(), inputs.end(), 0);

  using TIn = s64;
  using TOut = pair<s64, s64>;
  constexpr TOut kInvalid = pair<s64, s64>(0, -1);

  constexpr auto kMergeOutput = [](const TOut& l, const TOut& r) -> TOut {
    if (l.first > r.first) {
      return l;
    } else if (l.first == r.first) {
      return l.second > r.second ? l : r;
    } else {
      return r;
    }
  };

  constexpr auto kGetOutput = [](const TIn& in, const TOut& out) -> TOut {
    TOut ret = out;
    if (ret.second == -1) {
      ret.first = 1;
      ret.second = in;
    } else {
      ++ret.first;
    }
    return ret;
  };

  const auto result =
      util::rerooting_dp::solve<TIn, TOut, kInvalid, kMergeOutput, kGetOutput>(
          g, inputs);

  for (s64 i = 0; i < n; ++i) cout << result[i].second + 1 << endl;
}