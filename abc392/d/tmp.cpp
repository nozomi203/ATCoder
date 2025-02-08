#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N;
  cin >> N;

  struct dice {
    s64 num_face;
    map<s64, s64> prob_map;
  };
  vector<dice> dices(N);

  for (s64 i = 0; i < N; ++i) {
    auto& dice = dices[i];
    cin >> dice.num_face;

    for (s64 j = 0; j < dice.num_face; ++j) {
      s64 A;
      cin >> A;
      ++dice.prob_map[A];
    }
  }

  double prob_max{0.0};
  for (s64 i = 0; i < N - 1; ++i) {
    const dice& di = dices[i];
    for (s64 j = i + 1; j < N; ++j) {
      const dice& dj = dices[j];
      double prob{0.0};
      for (auto [vali, numi] : di.prob_map) {
        if (dj.prob_map.count(vali)) {
          auto numj = dj.prob_map.at(vali);
          prob += (numi * numj) / (double)(di.num_face * dj.num_face);
        }
      }
      prob_max = max(prob_max, prob);
    }
  }

  cout << fixed << setprecision(15) << prob_max << endl;
}
