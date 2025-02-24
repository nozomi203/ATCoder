#include "util/common.h"

int main() {
  string S;
  cin >> S;
  vector<stack<s64>> indices(3);

  const auto check = [&]() -> bool {
    for (s64 i = 0; i < S.size(); ++i) {
      switch (S[i]) {
        case '(':
          indices[0].push(i);
          break;
        case ')':
          if (indices[0].empty()) return false;
          if (!indices[1].empty() && indices[0].top() < indices[1].top())
            return false;
          if (!indices[2].empty() && indices[0].top() < indices[2].top())
            return false;
          indices[0].pop();
          break;
        case '[':
          indices[1].push(i);
          break;
        case ']':
          if (indices[1].empty()) return false;
          if (!indices[2].empty() && indices[1].top() < indices[2].top())
            return false;
          if (!indices[0].empty() && indices[1].top() < indices[0].top())
            return false;
          indices[1].pop();
          break;
        case '<':
          indices[2].push(i);
          break;
        case '>':
          if (indices[2].empty()) return false;
          if (!indices[0].empty() && indices[2].top() < indices[0].top())
            return false;
          if (!indices[1].empty() && indices[2].top() < indices[1].top())
            return false;
          indices[2].pop();
          break;
      }
    }
    return all_of(indices.begin(), indices.end(),
                  [](const auto& elem) { return elem.empty(); });
  };

  cout << (check() ? "Yes" : "No") << endl;
}