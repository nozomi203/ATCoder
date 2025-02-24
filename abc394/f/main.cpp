#include "util/common.h"

map<pair<s64, s64>, s64> g_mem;

s64 get_max_length(const vector<vector<s64>>& conns, s64 idx, s64 prev_idx,
                   bool& has_cross) {
  if (g_mem.count(make_pair(idx, prev_idx)))
    return g_mem.at(make_pair(idx, prev_idx));

  s64 ret{1};
  if (conns[idx].size() == 1) {
  } else if (conns[idx].size() < 4) {
    vector<s64> cands;
    for (auto conn_idx : conns[idx]) {
      if (conn_idx == prev_idx) continue;
      cands.push_back(get_max_length(conns, conn_idx, idx, has_cross));
    }
    sort(cands.begin(), cands.end(), std::greater());
    ret += cands[0];
  } else if (conns[idx].size() == 4) {
    has_cross = true;
    for (auto conn_idx : conns[idx]) {
      if (conn_idx == prev_idx) continue;
      ret += (get_max_length(conns, conn_idx, idx, has_cross));
    }
  } else {
    has_cross = true;
    vector<s64> cands;
    for (auto conn_idx : conns[idx]) {
      if (conn_idx == prev_idx) continue;
      cands.push_back(get_max_length(conns, conn_idx, idx, has_cross));
    }
    sort(cands.begin(), cands.end(), std::greater());
    for (s64 i = 0; i < 3; ++i) {
      ret += cands[i];
    }
  }

  g_mem.emplace(make_pair(idx, prev_idx), ret);
  return ret;
}

int main() {
  s64 N;
  cin >> N;
  vector<vector<s64>> conns(N + 1);
  for (s64 i = 0; i < N - 1; ++i) {
    s64 A, B;
    cin >> A >> B;
    conns[A].push_back(B);
    conns[B].push_back(A);
  }

  const auto get_ans = [&]() -> s64 {
    s64 idx{-1};
    for (s64 i = 0; i < N; ++i) {
      if (conns[i].size() == 1) {
        idx = i;
        break;
      }
    }
    if (idx < 0) return -1;
    bool has_cross{false};
    s64 max_length = get_max_length(conns, conns[idx][0], idx, has_cross) + 1;
    return has_cross ? max_length : -1;
  };

  cout << get_ans() << endl;
}