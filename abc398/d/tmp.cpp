#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 n;
  pair<s64, s64> man_pos;
  cin >> n >> man_pos.first >> man_pos.second;
  string s;
  cin >> s;
  set<pair<s64, s64>> smk_pos;

  const map<char, pair<s64, s64>> dirs = {
      {'N', {1, 0}},
      {'E', {0, -1}},
      {'W', {0, 1}},
      {'S', {-1, 0}},
  };

  smk_pos.emplace(make_pair(0, 0));
  pair<s64, s64> curr_pos{0, 0};
  for (s64 i{0}; i < n; ++i) {
    const char c{s[i]};
    auto dir = dirs.at(c);
    curr_pos.first += dir.first;
    curr_pos.second += dir.second;
    man_pos.first += dir.first;
    man_pos.second += dir.second;
    smk_pos.emplace(curr_pos);
    cout << (smk_pos.count(man_pos) ? '1' : '0');
  }
  cout << endl;
}
