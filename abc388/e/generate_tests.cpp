#include <algorithm>
#include <cstdint>
#include <format>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::mt19937 mt(std::random_device());
  std::uniform_int_distribution<uint32_t> dist1(2, 10);
  std::uniform_int_distribution<uint32_t> dist2(1, 100);
  constexpr uint32_t test_count = 10;
  for (uint32_t i = 0; i < test_count; ++i) {
    const auto num_data = dist1(mt);
    std::vector<uint32_t> data(num_data);
    for (int i = 0; i < num_data; ++i) {
      data[i] = dist2(mt);
    }
    std::sort(data.begin(), data.end());

    const auto filename_in = std::format("random-{}.in", i + 1);
    std::ofstream f_in(filename_in);
    if (f_in) {
      f_in << num_data << std::endl;
      for (int i = 0; i < num_data; ++i) {
        f_in << data[i];
        if (i < num_data - 1) f_in << " ";
      }
      f_in << std::endl;
      f_in.close();
    }

    const auto filename_out = std::format("random-{}.out");
  }
}