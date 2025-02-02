#include "util/common.h"
#include "util/string_distance.h"

int main() {
  s64 K;
  cin >> K;
  string S, T;
  cin >> S >> T;
  cout << (util::string_distance(S, T) <= K ? "Yes" : "No") << endl;
}