#include "util/common.h"
/*

1 2 3 4 5 6 7 8 9
10 11 12
13
0 1 2 3 4 5 6 7 8 depth 2
9 10 11 depth 1
12 depth 0

総数: 3^(n+1)-1 / (3-1) = 26 / 2 = 13
*/

s64 pow(s64 i, s64 j) {
  if (j == 0) return 1;
  return i * pow(i, j - 1);
}

int main() {
  s64 n, q;
  cin >> n >> q;
  string t;
  cin >> t;
  vector<s64> ps(q);
  util::cin(ps);

  struct node {
    s64 depth;
    s64 idx;
    char c;
  };

  const s64 total = (pow(3, n + 1) - 1) / 2;

  vector<node> nodes(total);

  const auto update_node = [&](node& node) {
    s64 cnta = 0;
    const s64 offst = (pow(3, node.depth - 1) - 1) / 2;
    if (nodes[offst + 0].c == 'A') ++cnta;
    if (nodes[offst + 1].c == 'A') ++cnta;
    if (nodes[offst + 2].c == 'A') ++cnta;
    node.c = cnta > 1 ? 'A' : 'B';
  };

  for (s64 i = 0; i < t.size(); ++i) {
    nodes.push_back(node{n, i, t[i]});
  }

  s64 cnt = pow(3, n);
  s64 offst = cnt;
  for (s64 d = n - 1; d >= 0; --d) {
    cnt /= 3;

    for (s64 i = 0; i < cnt; ++i) {
      nodes[offst + i].depth = d;
      nodes[offst + i].idx = i;
      update_node(nodes[offst + i]);
    }
    offst += cnt;
  }

  for (auto p : ps) {
    nodes[p - 1].c = nodes[p - 1].c == 'A' ? 'B' : 'A';
    node* pn = nodes[nodes[p-1].depth;
    while (pn != nullptr) {
      update_node(*pn);
    }
  }
}