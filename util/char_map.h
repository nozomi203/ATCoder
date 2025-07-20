#pragma once
#include <array>
#include <cstdint>

namespace util {
template <typename T, char Pivot = 'A', size_t Size = 26>
class char_map : public std::array<T, Size> {
 public:
  using base_type = std::array<T, Size>;
  using base_type::base_type;

 public:
  T& operator[](char c) { return (*this)[static_cast<size_t>(c - Pivot)]; }
};
}  // namespace util