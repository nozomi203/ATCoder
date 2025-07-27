#include "util/common.h"

s64 pow(s64 n, s64 p) {
  if (p == 0) return 1;
  return n * pow(n, p - 1);
}
int main() {
  for (size_t i = 0; i < 10; ++i) {
    const string fname_in = format("tests/sample_generated_{}.in", i);
    const string fname_out = format("tests/sample_generated_{}.out", i);
    ofstream ofin(fname_in), ofout(fname_out);

    random_device dev;
    mt19937 mt(dev());
    uniform_int_distribution<size_t> dk(1, 5);

    const size_t k = dk(mt);
    const size_t xmax = pow(5, k);
    uniform_int_distribution<size_t> dx(1, xmax);
    const size_t x = dx(mt);
    ofin << 5 << " " << k << " " << x;
    ofin << "a" << endl;
    ofin << "b" << endl;
    ofin << "c" << endl;
    ofin << "d" << endl;
    ofin << "e" << endl;

    vector<string> ss = {"a", "b", "c", "d", "e"};
    }
}