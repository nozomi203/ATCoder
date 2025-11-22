#include "util/common.h"

/*
飴の数を同じにする。
最終的に同数になった時の飴の数はaの合計から分かる

飴の数の合計が人数の倍数になっているとき操作列は存在する

dp[b] =
子供の集合bに対して、集合内の飴の数がすべての飴の個数の平均値で割り切れるようにするために
減らさなければいけない人数の最小値

*/

int main() {
  u64 n;
  cin >> n;
  vector<s64> as(n);
  util::cin(as);

  const auto get_ops = [&]() -> optional<vector<tuple<s64, s64, s64>>> {
    const s64 suma = accumulate(as.begin(), as.end(), 0);
    if (suma % n > 0) return nullopt;
    const s64 ave = suma / n;

    // dp[b]=集合bに属する子供の持つ飴の数の合計の、理想からのズレを0にするために減らす子供の数の最小
    vector<s64> dp(1ULL << n);
    // minb[i] =
    vector<u64> minis(1ULL << n);
    // sumdiffs[b] = 集合bに所属する子供の持つ飴玉の数の理想からのズレ
    vector<s64> sumdiffs(1ULL << n);

    for (u64 b = 1; b < (1ULL << n); ++b) {
      // calc sumdiff
      for (u64 i = 0; i < n; ++i) {
        if (b & (1ULL << i)) {
          sumdiffs[b] += (as[i] - ave);
        }
      }

      dp[b] = n + 1;
      for (u64 i = 0; i < n; ++i) {
        if (b & (1ULL << i)) {
          const s64 val = dp[b & ~(1ULL << i)] + (sumdiffs[b] == 0 ? 0 : 1);
          if (val < dp[b]) {
            dp[b] = val;
            minis[b] = i;
          }
        }
      }
    }

    u64 b = (1ULL << n) - 1;
    vector<tuple<s64, s64, s64>> ret;
    while (b) {
      vector<pair<s64, u64>> vec;
      while (true) {
        u64 mini = minis[b];
        vec.push_back(make_pair(as[mini], mini));
        b &= ~(1ULL << mini);

        if (sumdiffs[b] == 0) break;
      }
      sort(vec.begin(), vec.end(), greater());

      s64 sum = vec[0].first - ave;
      for (u64 i = 1; i < vec.size(); ++i) {
        ret.push_back(make_tuple(vec[i - 1].second, vec[i].second, sum));
        sum += vec[i].first - ave;
      }
    }
    return ret;
  };

  const auto ops = get_ops();
  if (!ops) {
    cout << -1 << endl;
  } else {
    cout << ops->size() << endl;
    for (auto [op0, op1, op2] : *ops)
      cout << op0 + 1 << " " << op1 + 1 << " " << op2 << endl;
  }
}