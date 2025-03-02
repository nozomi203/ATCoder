#include "../sparse_table.h"

#include <vector>

int main() {
  std::vector<int> data = {3, 1, 4, 1, 5, 9, 2};
  util::sparse_table<int, int> st(data);
}