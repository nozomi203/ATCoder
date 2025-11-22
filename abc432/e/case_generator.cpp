#include "util/common.h"
int main() {
  s64 n = 5;
  s64 q = 5;

  random_device dev;
  mt19937 engine(dev());
  uniform_int_distribution<s64> dist(0, 20), dist_c(1, 2), dist_x(1, n);

  for (s64 i = 0; i < 10; ++i) {
    vector<s64> as(n);
    for (s64 j = 0; j < n; ++j) as[j] = dist(engine);
    vector<tuple<s64, s64, s64>> queries(q);
    for (auto& [q0, q1, q2] : queries) {
      q0 = dist_c(engine);
      if (q0 == 1) {
        q1 = dist_x(engine);
        q2 = dist(engine);
      } else {
        q1 = dist(engine);
        q2 = dist(engine);
      }
    }

    const string fname_in = format("./tests/sample_generated_{}.in", i);
    const string fname_out = format("./tests/sample_generated_{}.out", i);

    auto fstream_in = ofstream(fname_in);
    auto fstream_out = ofstream(fname_out);

    fstream_in << n << " " << q << endl;
    for (s64 j = 0; j < n; ++j) {
      fstream_in << as[j];
      if (j < n - 1) fstream_in << " ";
    }
    fstream_in << endl;
    for (auto [q0, q1, q2] : queries)
      fstream_in << q0 << " " << q1 << " " << q2 << endl;

    for (auto [q0, q1, q2] : queries) {
      if (q0 == 1) {
        as[q1 - 1] = q2;
      } else {
        s64 ret = 0;
        for (auto a : as) ret += max(q1, min(q2, a));
        fstream_out << ret << endl;
      }
    }
  }
}