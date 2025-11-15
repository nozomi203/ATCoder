#include <atcoder/lazysegtree>

#include "util/common.h"

/*
トライ木？

*/

// dp[i][j] = 要素数iの集合のうち値iを{含むものの数、含まないものの数}
using elem_t = array<array<pair<u32, u32>, 61>, 61>;
using f_t = array<optional<bool>, 61>;
using atcoder::lazy_segtree<elem_t,
                            [](const elem_t& s0, const elem_t& s1) -> elem_t {
                              elem_t ret;
                              for (u32 i = 0; i <= 60; ++i) {
                                for (u32 j = 1; j <= 60; ++j) {
                                  ret[i][j].first =
                                      s0[i][j].first + s1[i][j].first;
                                  ret[i][j].second =
                                      s0[i][j].second + s1[i][j].second;
                                }
                              }
                              return ret;
                            },
                            []() -> elem_t { return elem_t{}; }, f_t,
                            [](const f_t& f, const elem_t& s) -> elem_t {
                              elem_t ret = s;
                              for (u32 j = 1; j <= 60; ++j) {
                                if (!f[j]) continue;
                                const bool b = *f[j];
                                for (u32 i = 0; i < 60; ++i) {
                                  if (b) {
                                    ret[i + 1][j].first += ret[i][j].second;
                                    ret[i][j].second = 0;
                                  }
                                }
                              }
                            },
                            [](const f_t& f0, const f_t& f1) -> f_t {

                            },
                            []() -> f_t {}>;

int main() {
  s64 n, q;
  cin >> n >> q;
  vector<tuple<s64, s64, s64, s64>> queries(q);
  util::cin(queries);
  for (auto [q, l, r, x] : queries) {
  }
}