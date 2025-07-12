#pragma once

#include <vector>

namespace util {

template <typename T, size_t Dim>
class multi_vector : public std::vector<multi_vector<T, Dim - 1>> {
 public:
  using base_type = std::vector<multi_vector<T, Dim - 1>>;

 public:
  template <size_t... Sizes>
  multi_vector(const T& v, size_t size, Sizes... sizes)
      : base_type(v, sizes...) {}
};

template <typename T>
class multi_vector<T, 1> : public : std::vector<t> {};

template <typename T>
class multi_vector<T, 0> {};

}  // namespace util
