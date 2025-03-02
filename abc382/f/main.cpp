#include "util/common.h"
#include "util/lazy_segment_tree.h"

int main() {
  s64 H, W, N;
  cin >> H >> W >> N;
  struct Bar {
    s64 idx;
    s64 r;
    s64 c;
    s64 l;
  };
  vector<Bar> bars(N);
  for (s64 i = 0; i < N; ++i) {
    bars[i].idx = i;
    cin >> bars[i].r >> bars[i].c >> bars[i].l;
  }

  std::sort(bars.begin(), bars.end(),
            [](const auto& a, const auto& b) { return a.r > b.r; });

  vector<s64> answers(N);

  constexpr auto opFunc = [](s64 l, s64 r) { return max(l, r); };
  constexpr auto compFunc = [](s64 f_new, s64 f_old) { return f_new; };
  constexpr auto mapFunc = [](s64 f, s64 s) { return f; };
  util::lazy_segment_tree<s64, s64, 0, opFunc, mapFunc, compFunc> lst(W + 1);
  for (const auto& bar : bars) {
    auto h = lst.query(bar.c, bar.c + bar.l);
    lst.apply(bar.c, bar.c + bar.l, h + 1);
    answers[bar.idx] = H - h;
  }

  for (auto ans : answers) {
    cout << ans << endl;
  }
}