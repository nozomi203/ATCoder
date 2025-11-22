#include <atcoder/dsu>

#include "util/common.h"

/*
1回の操作における連結成分の数の増加は高々2倍
n<=14なので、全部の操作が終わった時の連結成分の数は高々2^14 = 10^4
シミュレーションできそう
大事なこととして、分割されたグループがのちの操作で重なりあうことはない
*/

int main() {
  s64 n, x, y;
  cin >> n >> x >> y;
  vector<tuple<char, s64, s64>> cabs(n);
  util::cin(cabs);

  struct group_t {
    s64 px;
    s64 py;
    s64 nx;
    s64 ny;
  };

  vector<group_t> groups;
  groups.push_back(group_t{0, 0, x, y});

  for (auto [c, a, b] : cabs) {
    vector<group_t> add;
    if (c == 'X') {
      for (auto& group : groups) {
        if (group.px >= a) {
          group.py += b;
        } else if (group.px + group.nx <= a) {
          group.py -= b;
        } else {
          const s64 dnx = group.nx - (a - group.px);
          group.nx -= dnx;
          add.push_back(
              group_t{group.px + group.nx, group.py + b, dnx, group.ny});
          group.py -= b;
        }
      }
    } else {
      for (auto& group : groups) {
        if (group.py >= a) {
          group.px += b;
        } else if (group.py + group.ny <= a) {
          group.px -= b;
        } else {
          const s64 dny = group.ny - (a - group.py);
          group.ny -= dny;
          add.push_back(
              group_t{group.px + b, group.py + group.ny, group.nx, dny});
          group.px -= b;
        }
      }
    }
    for (auto ng : add) groups.push_back(ng);
  }

  atcoder::dsu uf(groups.size());

  /*
  連結成分の判定
  */

  map<s64, vector<s64>> mxl, mxr, myl, myr;

  for (s64 i = 0; i < groups.size(); ++i) {
    group_t& group = groups[i];
    mxl[group.px].push_back(i);
    mxr[group.px + group.nx - 1].push_back(i);
    myl[group.py].push_back(i);
    myr[group.py + group.ny - 1].push_back(i);
  }

  for (auto [xr, pgsr] : mxr) {
    for (auto pgl : mxl[xr + 1]) {
      for (auto pgr : pgsr) {
        group_t& gl = groups[pgl];
        group_t& gr = groups[pgr];
        if (gl.py >= gr.py + gr.ny) continue;
        if (gr.py >= gl.py + gl.ny) continue;
        uf.merge(pgl, pgr);
      }
    }
  }
  for (auto [yr, pgsr] : myr) {
    for (auto pgl : myl[yr + 1]) {
      for (auto pgr : pgsr) {
        group_t& gl = groups[pgl];
        group_t& gr = groups[pgr];
        if (gl.px >= gr.px + gr.nx) continue;
        if (gr.px >= gl.px + gl.nx) continue;
        uf.merge(pgl, pgr);
      }
    }
  }

  const auto ret = uf.groups();

  vector<s64> answers(ret.size());
  for (s64 i = 0; i < ret.size(); ++i) {
    auto& vec = ret[i];
    for (auto j : vec) {
      answers[i] += groups[j].nx * groups[j].ny;
    }
  }

  sort(answers.begin(), answers.end());
  cout << answers.size() << endl;
  for (s64 i = 0; i < answers.size(); ++i) {
    cout << answers[i];
    if (i < answers.size() - 1) cout << " ";
  }
  cout << endl;

  return 0;
}
