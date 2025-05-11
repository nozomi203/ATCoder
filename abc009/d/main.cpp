#include "util/bit.h"
#include "util/common.h"

class matrix {
 public:
  using value_type = uint64_t;

 public:
  matrix() = default;
  matrix(const matrix& other) = default;
  matrix(matrix&& other) = default;
  matrix(size_t h, size_t w) : m_h(h), m_w(w), m_v(h * w) {}

  matrix& operator=(const matrix& other) = default;
  matrix& operator=(matrix&& other) = default;

  std::span<const value_type> operator[](size_t idx) const {
    return std::span<const value_type>(m_v.cbegin() + m_w * idx, m_w);
  }

  std::span<value_type> operator[](size_t idx) {
    return std::span<value_type>(m_v.begin() + m_w * idx, m_w);
  }

  size_t height() const { return m_h; }
  size_t width() const { return m_w; }

  matrix operator*(const matrix& rhs) {
    assert(m_w == rhs.m_h);
    matrix ret(m_h, rhs.m_w);
    for (size_t h{0}; h < ret.height(); ++h) {
      for (size_t w{0}; w < ret.width(); ++w) {
        for (size_t i{0}; i < m_w; ++i) {
          ret[h][w] ^= (*this)[h][i] & rhs[i][w];
        }
      }
    }
    return ret;
  }

 private:
  size_t m_h{0};
  size_t m_w{0};
  std::vector<value_type> m_v;
};

int main() {
  u64 k, m;
  cin >> k >> m;
  vector<u64> a(k), c(k);
  for (u64 i{0}; i < k; ++i) cin >> a[i];
  for (u64 i{0}; i < k; ++i) cin >> c[i];

  vector<matrix> mats(64, matrix(k, k));
  for (u64 i{0}; i < k; ++i) mats[0][0][i] = c[i];
  for (u64 i{1}; i < k; ++i) mats[0][i][i - 1] = numeric_limits<u64>::max();

  for (u64 i{1}; i < mats.size(); ++i) {
    mats[i] = mats[i - 1] * mats[i - 1];
  }

  const auto get = [&]() -> u64 {
    if (m <= k) return a[m - 1];
    m -= k;

    matrix mat(k, 1);
    for (u64 i{0}; i < k; ++i) mat[i][0] = a[k - 1 - i];

    u64 pow{0};
    while (m) {
      if (m & (1 << pow)) {
        mat = mats[pow] * mat;
        m &= ~(1 << pow);
      }
      ++pow;
    }

    return mat[0][0];
  };

  cout << get() << endl;
}