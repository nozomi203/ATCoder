#include "util/common.h"
#include "util/union_find_tree.h"

int main() {
  s64 N, M;
  cin >> N >> M;

  util::union_find_tree uft(N + 1);
  vector<map<s64, s64>> connections(N + 1);
  for (s64 i = 1; i <= M; ++i) {
    s64 A, B;
    cin >> A >> B;
    connections[A].emplace(B, i);
    connections[B].emplace(A, i);
    uft.unite(A, B);
  }

  set<s64> lerders;
  for (s64 i = 1; i <= N; ++i) {
    lerders.emplace(uft.leader(i));
  }

  if (lerders.size() == 1) {
    cout << 0 << endl;
    return;
  }
  struct change {
    s64 cable_idx;
    s64 server_prev_idx;
    s64 server_next_idx;
  };
  vector<change> changes;

  vector<bool> seen(N + 1, false);
  struct work {
    s64 server_prev_idx;
    s64 server_curr_idx;
  };
  stack<work> works;
  auto itr = lerders.begin();
  works.push(work{*itr, -1});
  ++itr;
  while (!works.empty()) {
    auto [prev, curr] = works.top();
    works.pop();

    if (seen[curr]) {
      changes.push_back(change{});
    }

    for (auto connection : connections[curr]) {
      works.push(work{curr, connection});
    }
  }
}