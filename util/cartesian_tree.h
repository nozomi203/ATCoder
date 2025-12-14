#pragma once
#include <concepts>
#include <stack>
#include <type_traits>
#include <vector>

namespace util {

template <std::integral T, auto Comparer>
class cartesian_tree {
 public:
  static_assert(std::is_invocable_r_v<bool, decltype(Comparer), T, T>);

 public:
  cartesian_tree(const std::vector<T>& vs) {
    const size_t n = vs.size();
    m_pidxs.resize(n, -1);
    m_lidxs.resize(n, -1);
    m_ridxs.resize(n, -1);

    std::stack<size_t> s;
    for (size_t i = 0; i < n; ++i) {
      while (!s.empty() && Comparer(vs[s.top()], vs[i])) {
        const T j = s.top();
        s.pop();
        m_pidxs[j] = i;
        m_lidxs[i] = j;
      }

      if (s.empty()) {
        m_root = i;
        s.push(i);
      } else {
        const T j = s.top();
        s.push(i);
        m_pidxs[i] = j;
        m_ridxs[j] = i;
      }
    }
  }

  T get_root() const { return m_root; }
  T get_p(size_t idx) const { return m_pidxs[idx]; }
  T get_l(size_t idx) const { return m_lidxs[idx]; }
  T get_r(size_t idx) const { return m_ridxs[idx]; }

 private:
  size_t m_root{0};
  std::vector<T> m_pidxs;
  std::vector<T> m_lidxs;
  std::vector<T> m_ridxs;
};

}  // namespace util