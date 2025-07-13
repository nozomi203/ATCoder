#include "util/common.h"

int main() {
  const auto check = [](size_t v, size_t a) -> bool {
    vector<size_t> seq;
    while (v) {
      seq.push_back(v % a);
      v /= a;
    }

    for (s64 i = 0; i < seq.size() / 2; ++i) {
      if (seq[i] != seq[seq.size() - 1 - i]) return false;
    }
    return true;
  };

  const size_t ns[] = {1, 10, 100, 1000, 10000};
  for (size_t a = 2; a <= 9; ++a) {
    for (size_t n : ns) {
      const string fname_in = format("./tests/sample-{}_{}.in", a, n);
      const string fname_out = format("./tests/sample-{}_{}.out", a, n);

      ofstream fin(fname_in), fout(fname_out);

      fin << a << endl;
      fin << n << endl;

      size_t sum = 0;
      for (size_t i = 1; i <= n; ++i) {
        if (check(i, 10) && check(i, a)) sum += i;
      }
      fout << sum << endl;

      fin.close();
      fout.close();
    }
  }
}