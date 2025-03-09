#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, M;
  cin >> N >> M;
  vector<vector<s64>> conns(N + 1);
  for (s64 i{0}; i < M; ++i) {
    s64 a, b;
    cin >> a >> b;
    conns[a].push_back(b);
  }

  const auto get = [&]() -> s64 {
    struct work {
      s64 node;
      s64 depth;
    };
    queue<work> works;
    works.push(work{1, 0});
    while (!works.empty()) {
      const auto w = works.front();
      works.pop();
      for (const auto conn : conns[w.node]) {
        if (conn == 1) return w.depth + 1;
        works.push(work{conn, w.depth + 1});
      }
    }
    return -1;
  };

  cout << get() << endl;
}
