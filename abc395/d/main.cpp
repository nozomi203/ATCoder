#include "util/common.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;

  vector<s64> p_loc(N + 1), h_label(N + 1), label_loc(N + 1);
  for (s64 i = 1; i <= N; ++i) {
    p_loc[i] = i;
    h_label[i] = i;
    label_loc[i] = i;
  }

  vector<s64> answers;
  for (s64 i = 0; i < Q; ++i) {
    s64 q;
    cin >> q;
    if (q == 1) {
      s64 a, b;
      cin >> a >> b;
      p_loc[a] = label_loc[b];
    } else if (q == 2) {
      s64 a, b;
      cin >> a >> b;
      s64 h_label_a{h_label[label_loc[a]]}, h_label_b{h_label[label_loc[b]]};
      swap(h_label[label_loc[a]], h_label[label_loc[b]]);
      swap(label_loc[h_label_a], label_loc[h_label_b]);
    } else {
      s64 a;
      cin >> a;
      answers.push_back(h_label[p_loc[a]]);
    }
  }

  for (auto ans : answers) {
    cout << ans << endl;
  }
}