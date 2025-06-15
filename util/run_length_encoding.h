#pragma once
#include <vector>

namespace util::run_length_encoding {
template <typename T>
inline std::vector<std::pair<T, size_t>> encode(const std::vector<T>& values) {
  std::vector<std::pair<T, size_t>> encoded;
  if (values.empty()) return encoded;

  T current_value = values[0];
  size_t count = 1;

  for (size_t i = 1; i < values.size(); ++i) {
    if (values[i] == current_value) {
      ++count;
    } else {
      encoded.emplace_back(current_value, count);
      current_value = values[i];
      count = 1;
    }
  }

  // Add the last accumulated value
  encoded.emplace_back(current_value, count);

  return encoded;
}
}  // namespace util::run_length_encoding