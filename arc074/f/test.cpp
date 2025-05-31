#include <atcoder/maxflow.hpp>

#include "util/common.h"

int main() {
  atcoder::mf_graph<s64> mfg(2);
  mfg.add_edge(0, 1, 1);
  cout << mfg.flow(0, 1) << endl;
}