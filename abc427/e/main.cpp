#include "util/common.h"

/*
H,W<=12の制約により、全マスの状態をビットで管理できる
ゴミの数は最大H*W-1=143
*/

int main() {
  u32 h, w;
  cin >> h >> w;
  vector<string> ss(h);
  util::cin(ss);

  u32 th = 0, tw = 0;
  for (u32 i = 0; i < h; ++i) {
    bool brk = false;
    for (u32 j = 0; j < w; ++j) {
      if (ss[i][j] == 'T') {
        th = i;
        tw = j;
        brk = true;
        break;
      }
    }
    if (brk) break;
  }

  using state_t = array<u32, 12>;
  queue<state_t> q;
  map<state_t, u64> m;
  {
    state_t state{};
    for (u32 i = 0; i < h; ++i) {
      u32 b = 0;
      for (u32 j = 0; j < w; ++j) {
        if (ss[i][j] == '#') b |= (1U << j);
        state[i] = b;
      }
    }
    q.push(state);
    m[state] = 0;
  }
  while (!q.empty()) {
    state_t cur = q.front();
    q.pop();

    const u32 mask = (1U << w) - 1U;
    {
      state_t nxt = cur;
      for (u32 i = h - 1; i > 0; --i) nxt[i] = nxt[i - 1];
      nxt[0] = 0;
      if (!(nxt[th] & (1U << tw))) {
        if (!m.contains(nxt)) {
          q.push(nxt);
          m[nxt] = m[cur] + 1;
        }
      }
    }
    {
      state_t nxt = cur;
      for (u32 i = 0; i < h - 1; ++i) nxt[i] = nxt[i + 1];
      nxt[h - 1] = 0;
      if (!(nxt[th] & (1U << tw))) {
        if (!m.contains(nxt)) {
          q.push(nxt);
          m[nxt] = m[cur] + 1;
        }
      }
    }
    {
      state_t nxt = cur;
      for (u32 i = 0; i < h; ++i) nxt[i] = (nxt[i] << 1U) & mask;
      if (!(nxt[th] & (1U << tw))) {
        if (!m.contains(nxt)) {
          q.push(nxt);
          m[nxt] = m[cur] + 1;
        }
      }
    }
    {
      state_t nxt = cur;
      for (u32 i = 0; i < h; ++i) nxt[i] = (nxt[i] >> 1U);
      if (!(nxt[th] & (1U << tw))) {
        if (!m.contains(nxt)) {
          q.push(nxt);
          m[nxt] = m[cur] + 1;
        }
      }
    }
  }

  {
    state_t state{};
    if (m.contains(state)) {
      cout << m[state] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}