#include "../lca.h"

#include "../test.h"

int main() {
  std::vector<std::vector<size_t>> tree = {{1, 2}, {3, 4}, {}, {5},
                                           {6, 7}, {},     {}, {}};
  util::lca lca(tree, 0);
  TEST(lca.query(5, 4), 1);
  TEST(lca.query(0, 1), 0);
  TEST(lca.query(5, 2), 0);
  TEST(lca.query(3, 5), 3);
  TEST(lca.query(6, 7), 4);
  TEST(lca.query(2, 2), 2);
}
