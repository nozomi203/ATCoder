#include "util/common.h"

int main() {
  string S;
  cin >> S;
  for (auto itr = S.begin(); itr != S.end();) {
    if (*itr != '2') {
      itr = S.erase(itr);
    } else {
      ++itr;
    }
  }

  cout << S << endl;
}