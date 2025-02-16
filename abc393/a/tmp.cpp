#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  bool b1 = s1 == "sick" ? true : false;
  bool b2 = s2 == "sick" ? true : false;
  const auto get_ans = [&]() {
    if (b1 && b2) return 1;
    if (b1 && !b2) return 2;
    if (!b1 && b2) return 3;
    return 4;
  };

  cout << get_ans() << endl;
}
