#include "../sparse_table.h"

#include <vector>

#include "../test.h"

int main() {
  std::vector<int> data = {3, 1, 4, 1, 5, 9, 2};
  constexpr auto kOpFunc = [](int l, int r) { return std::min(l, r); };
  util::sparse_table<int, kOpFunc> st(data);
  TEST(st.query(0, 2), 1);
  TEST(st.query(0, 6), 1);
  TEST(st.query(5, 5), 9);
  TEST(st.query(4, 6), 2);
}