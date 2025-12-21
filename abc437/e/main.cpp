#include "util/common.h"
/*
Aiを辞書順でならべたときのAの添え字の順列Pをもとめる。
Ai,Ajが完全一致するときはi<jとなるように並べる
*/

int main() {
  s64 n;
  cin >> n;
  vector<pair<s64, s64>> xys(n);
  util::cin(xys);

  struct node_t {
    set<s64> mems;
    map<s64, s64> cidxs;
  };
  vector<node_t> nodes(1);
  nodes[0].mems.emplace(0);
  vector<s64> idxs(n + 1, -1);
  idxs[0] = 0;
  for (s64 i = 1; i <= n; ++i) {
    auto [x, y] = xys[i - 1];
    const s64 idx = idxs[x];
    node_t& node = nodes[idx];
    if (node.cidxs.count(y)) {
      const auto cidx = node.cidxs[y];
      nodes[cidx].mems.emplace(i);
      idxs[i] = cidx;
    } else {
      idxs[i] = nodes.size();
      node.cidxs[y] = nodes.size();
      node_t& newnode = nodes.emplace_back();
      newnode.mems.emplace(i);
    }
  }

  vector<s64> answers;
  stack<s64> s;
  s.push(0);
  while (!s.empty()) {
    const auto idx = s.top();
    s.pop();

    const node_t& node = nodes[idx];

    for (auto mem : node.mems) answers.push_back(mem);

    for (auto rit = node.cidxs.rbegin(); rit != node.cidxs.rend(); ++rit) {
      auto [val, nxt] = *rit;
      s.push(nxt);
    }
  }

  for (s64 i = 1; i < answers.size(); ++i) {
    cout << answers[i];
    if (i < answers.size() - 1) cout << " ";
  }
  cout << endl;
}