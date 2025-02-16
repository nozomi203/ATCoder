#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  struct node {
    s64 from;
    s64 to;
    s64 score;
  };
  vector<node> nodes(M);
  for (size_t i = 0; i < M; ++i) {
    cin >> nodes[i].from >> nodes[i].to >> nodes[i].score;
  }
  vector<bool> inf(N + 1, false);
  vector<s64> max_scores(N + 1, numeric_limits<s64>::lowest());
  max_scores[1] = 0;
  size_t rep{0};
  while (rep < N) {
    bool dirty{false};
    for (const node& n : nodes) {
      if (max_scores[n.from] > numeric_limits<s64>::lowest() &&
          max_scores[n.from] + n.score > max_scores[n.to]) {
        max_scores[n.to] = max_scores[n.from] + n.score;
        dirty = true;
        if (rep == N - 1) inf[n.to] = true;
      }
    }
    if (!dirty) break;
    ++rep;
  }
  rep = 0;
  while (rep < N) {
    for (const node& n : nodes) {
      if (inf[n.from]) {
        inf[n.to] = true;
      }
    }
    ++rep;
  }

  if (inf[N]) {
    cout << "inf" << endl;
  } else {
    cout << max_scores[N] << endl;
  }
}