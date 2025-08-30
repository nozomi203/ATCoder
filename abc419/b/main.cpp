#include "util/common.h"

int main() {
  s64 q;
  cin >> q;

  priority_queue<s64, vector<s64>, greater<s64>> pq;
  for (s64 i = 0; i < q; ++i) {
    s64 q1;
    cin >> q1;
    if (q1 == 1) {
      s64 q2;
      cin >> q2;
      pq.push(q2);
    } else {
      cout << pq.top() << endl;
      pq.pop();
    }
  }
}