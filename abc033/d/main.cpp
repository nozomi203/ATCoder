#include "util/common.h"

using vec2 = pair<int64_t, int64_t>;

int64_t dot(const vec2& v0, const vec2& v1) {
  return v0.first * v1.first + v0.second * v1.second;
}

int64_t cross(const vec2& v0, const vec2& v1) {
  return v0.first * v1.second - v0.second * v1.first;
}

int main() {
  size_t n;
  cin >> n;
  vector<vec2> xys(n);
  for (size_t i{0}; i < n; ++i) cin_pair(xys[i]);
  vector<vector<vec2>> vtxss(n);
  for (size_t i{0}; i < n; ++i) {
    vtxss[i].reserve(n - 1);
    for (size_t j{0}; j < n; ++j) {
      if (i == j) continue;
      const int64_t dx{xys[j].first - xys[i].first},
          dy{xys[j].second - xys[i].second};
      vtxss[i].push_back(make_pair(dx, dy));
    }
  }
  for (size_t i{0}; i < n; ++i) {
    auto& vtxs{vtxss[i]};
    auto it = partition(vtxs.begin(), vtxs.end(),
                        [&](const vec2& vtx) { return vec2{} < vtx; });
    const auto cmp = [&](const vec2& vtx0, const vec2& vtx1) {
      return vtx0.first * vtx1.second > vtx0.second * vtx1.first;
    };
    sort(vtxs.begin(), it, cmp);
    sort(it, vtxs.end(), cmp);
  }

  /*
  鈍角三角形・直角三角形を数え上げる。残りが鋭角三角形
  */
  const size_t cnt_all{n * (n - 1) * (n - 2) / 6};
  size_t cnt_90{0};
  size_t cnt_gt_90{0};
  for (size_t i{0}; i < n; ++i) {
    const auto& vtxs{vtxss[i]};
    int64_t l{0}, r{0};
    for (size_t j{0}; j < n - 1; ++j) {
      while (dot(vtxs[j], vtxs[l]) > 0) {
        l = (l + 1) % (n - 1);
        if (l == j) break;
      }
      if (l == j) {
        l = (l + 1) % (n - 1);
        continue;
      }
      if (cross(vtxs[j], vtxs[l]) <= 0) {
        continue;
      }
      r = l;
      while (cross(vtxs[j], vtxs[r]) > 0) {
        r = (r + 1) % (n - 1);
      }
      if (r != l) {
        size_t tmp_cnt_90{0};
        if (dot(vtxs[j], vtxs[l]) == 0) ++tmp_cnt_90;
        if ((r + (n - 1) - 1) % (n - 1) != l) {
          if (dot(vtxs[j], vtxs[(r + (n - 1) - 1) % (n - 1)]) == 0)
            ++tmp_cnt_90;
        }
        cnt_90 += tmp_cnt_90;
        cnt_gt_90 += ((r + (n - 1) - l) % (n - 1)) - tmp_cnt_90;
      }
      if (l == j) l = (l + 1) % (n - 1);
    }
  }
  cout << cnt_all - (cnt_90 + cnt_gt_90) << " " << cnt_90 << " " << cnt_gt_90
       << endl;
}