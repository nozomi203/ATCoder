#include "util/common.h"

int main() {
  s64 Q;
  cin >> Q;
  vector<s64> answers;
  vector<s64> lens(1, 0);  // lens[i] = i番目のへびの長さ
  vector<s64> sums(1, 0);  // sums[i] = i番目のへびまでの長さの合計
  s64 delCnt{0};
  for (s64 i = 0; i < Q; ++i) {
    s64 Q1, Q2;
    cin >> Q1;
    switch (Q1) {
      case 1:
        cin >> Q2;
        lens.push_back(Q2);
        sums.push_back(sums.back() + Q2);
        break;
      case 2:
        ++delCnt;
        break;
      case 3:
        cin >> Q2;
        answers.push_back(sums[Q2 + delCnt - 1] - sums[delCnt]);
        break;
      default:
        break;
    }
  }

  if (answers.empty()) {
    cout << endl;
  } else {
    for (auto ans : answers) {
      cout << ans << endl;
    }
  }
}