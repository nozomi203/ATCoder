#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 q;
  cin >> q;
  queue<s64> queue;
  vector<s64> answers;
  for (s64 i{0}; i < q; ++i) {
    s64 a;
    cin >> a;
    if (a == 1) {
      s64 x;
      cin >> x;
      queue.push(x);
    } else {
      if (!queue.empty()) {
        answers.push_back(queue.front());
        queue.pop();
      }
    }
  }

  for (auto ans : answers) cout << ans << endl;
  if (answers.empty()) {
    cout << endl;
  }
}