#include "util/common.h"
#include "util/run_length_encoding.h"

int main() {
  string s;
  cin >> s;
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '#') {
      cout << '#';
    } else if (s[i] == '.') {
      if (i == 0 || s[i - 1] == '#') {
        cout << 'o';
      } else {
        cout << '.';
      }
    }
  }
  cout << endl;
}