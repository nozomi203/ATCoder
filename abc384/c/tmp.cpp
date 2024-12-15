#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  array<s64, 5> points;
  cin >> points[4] >> points[3] >> points[2] >> points[1] >> points[0];

  vector<pair<s64, s64>> ipPairs;
  for (s64 id = 1; id <= 31; ++id) {
    s64 p{0};
    for (s64 i = 0; i < 5; ++i) {
      s64 mask = (1 << i);
      if (id & mask) {
        p += points[i];
      }
    }
    ipPairs.push_back({id, p});
  }
  sort(ipPairs.begin(), ipPairs.end(), [](const auto& ipl, const auto& ipr) {
    if (ipl.second == ipr.second) {
      return ipl.first > ipr.first;
    }
    return ipl.second > ipr.second;
  });

  for (const auto& ipPair : ipPairs) {
    for (s64 i = 4; i >= 0; --i) {
      s64 mask = (1 << i);
      if (ipPair.first & mask) {
        cout << (char)('E' - i);
      }
    }
    cout << endl;
  }
}
