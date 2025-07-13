#include "util/common.h"

/*
ダイクストラ法。ただし、明らかに最短となりえないノードは後で追加することにする　
*/
int main() {
  size_t n, m;
  cin >> n >> m;
  vector<s64> xs(n);
  util::cin(xs);
  vector<tuple<s64, s64, s64, s64, s64>> lrLRcs(m);
  util::cin(lrLRcs);
  for (auto& [l, r, L, R, c] : lrLRcs) {
    --l;
    --r;
    --L;
    --R;
  }

  while (n < bit_ceil(n)) {
    xs.push_back(xs.back());
    ++n;
  }

  assert(n == bit_ceil(n));
  const size_t pown = countl_zero(n);
  const size_t nnode = 3 * n - 2;

  constexpr auto inf = numeric_limits<size_t>::max();
  struct node {
    s64 x;
    vector<size_t> idxs;
  };
  const size_t root_in = n;
  const size_t root_out = 2 * n - 1;

  vector<node> nodes(nnode);
  for (size_t i = 0; i < n; ++i) {
    nodes[i].x = xs[i];
  }
  {
    size_t offset = root_in;
    size_t width = n / 2;
    for (size_t w = 0; w < width; ++w) {
      nodes[offset + w].idxl = w * 2 + 0;
      nodes[offset + w].idxr = w * 2 + 1;
      nodes[offset + w].x = nodes[nodes[offset + w].idxl].x;
    }
    offset += width;
    width >>= 1;
    while (width) {
      for (size_t w = 0; w < width; ++w) {
        nodes[offset + w].idxl = offset - width * 2 + w * 2 + 0;
        nodes[offset + w].idxr = offset - width * 2 + w * 2 + 1;
        nodes[offset + w].x = nodes[nodes[offset + w].idxl].x;
      }
      offset += width;
      width >>= 1;
    }
    assert(offset == root_out);
  }
  {
    size_t offset = root_out;
    size_t width = n / 2;
    for (size_t w = 0; w < width; ++w) {
      nodes[offset + w].idxl = w * 2 + 0;
      nodes[offset + w].idxr = w * 2 + 1;
      nodes[offset + w].x = nodes[nodes[offset + w].idxl].x;
    }
    offset += width;
    width >>= 1;
    while (width) {
      for (size_t w = 0; w < width; ++w) {
        nodes[offset + w].idxl = offset - width * 2 + w * 2 + 0;
        nodes[offset + w].idxr = offset - width * 2 + w * 2 + 1;
        nodes[offset + w].x = nodes[nodes[offset + w].idxr].x;
      }
      offset += width;
      width >>= 1;
    }
    assert(offset == nnode);
  }

  const auto add_node = [&](size_t l, size_t r, size_t L, size_t R,
                            size_t c) -> void {
    size_t idx_out = nodes.size();
    nodes.emplace_back
  };
}