#include "util/binary_search.h"
#include "util/common.h"

int main() {
  s64 n, x;
  cin >> n >> x;
  struct proc {
    s64 a;
    s64 p;
    s64 b;
    s64 q;
  };
  vector<proc> procs(n);
  for (s64 i{0}; i < n; ++i)
    cin >> procs[i].a >> procs[i].p >> procs[i].b >> procs[i].q;

  constexpr s64 w_max = 1000000001;

  constexpr auto inf = numeric_limits<s64>::max();

  auto [w_ok, w_ng] = util::binary_search<s64>(0, w_max, [&](s64 w) -> bool {
    s64 min_total_cost{0};
    for (s64 i{0}; i < n; ++i) {
      s64 min_cost{inf};
      for (s64 j{0}; j <= procs[i].b; ++j) {
        s64 cost = procs[i].p * j;
        const s64 w_rem = max<s64>(0, w - procs[i].a * j);
        cost += procs[i].q * ((w_rem + procs[i].b - 1) / procs[i].b);
        min_cost = min(min_cost, cost);
      }
      for (s64 j{0}; j <= procs[i].a; ++j) {
        s64 cost = procs[i].q * j;
        const s64 w_rem = max<s64>(0, w - procs[i].b * j);
        cost += procs[i].p * ((w_rem + procs[i].a - 1) / procs[i].a);
        min_cost = min(min_cost, cost);
      }
      min_total_cost += min_cost;
    }
    return min_total_cost <= x;
  });

  cout << w_ok << endl;
}