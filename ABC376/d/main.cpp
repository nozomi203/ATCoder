#include "util/common.h"

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