#include "util/common.h"

int main() {
  random_device dev;
  mt19937 mt(dev());
  uniform_int_distribution<s64> dist(0, 10), distp(0, 30), distxyz(1, 5);

  for (size_t i = 0; i < 50; ++i) {
    const auto fnin = format("tests/sample_generated_{}.in", i);
    const auto fnout = format("tests/sample_generated_{}.out", i);
    ofstream ofin(fnin), ofout(fnout);

    const s64 x = distxyz(mt);
    const s64 y = distxyz(mt);
    const s64 z = distxyz(mt);

    ofin << x << " " << y << " " << z << " ";

    const s64 p = distp(mt);
    ofin << p << endl;

    vector<s64> as(x), bs(y), cs(z);
    for (s64 j = 0; j < x; ++j) {
      as[j] = dist(mt);
      ofin << as[j];
      if (j < x - 1) ofin << " ";
    }
    ofin << endl;
    for (s64 j = 0; j < y; ++j) {
      bs[j] = dist(mt);
      ofin << bs[j];
      if (j < y - 1) ofin << " ";
    }
    ofin << endl;
    for (s64 j = 0; j < z; ++j) {
      cs[j] = dist(mt);
      ofin << cs[j];
      if (j < z - 1) ofin << " ";
    }
    ofin << endl;

    const auto choose_c = [&](s64 v) -> s64 {
      s64 ret = 0;
      for (auto c : cs) {
        ret = max(ret, abs(v + c - p));
      }
      return ret;
    };
    const auto choose_b = [&](s64 v) -> s64 {
      s64 ret = 100000;
      for (auto b : bs) {
        ret = min(ret, choose_c(v + b));
      }
      return ret;
    };
    const auto choose_a = [&]() -> s64 {
      s64 ret = 0;
      for (auto a : as) {
        ret = max(ret, choose_b(a));
      }
      return ret;
    };
    const s64 ans = choose_a();
    ofout << ans << endl;
  }
}