#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 n, m, q;
  cin >> n >> m >> q;
  vector<set<s64>> perm(n + 1);
  vector<s64> adm(n + 1, false);
  vector<bool> answers;
  for (s64 i{0}; i < q; ++i) {
    s64 a;
    cin >> a;
    if (a == 1) {
      s64 x, y;
      cin >> x >> y;
      perm[x].emplace(y);
    } else if (a == 2) {
      s64 x;
      cin >> x;
      adm[x] = true;
    } else {
      s64 x, y;
      cin >> x >> y;
      answers.push_back(adm[x] || perm[x].count(y) > 0);
    }
  }

  for (auto ans : answers) {
    cout << (ans ? "Yes" : "No") << endl;
  }
}