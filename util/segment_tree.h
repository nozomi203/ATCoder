#include <cstdint>
#include <iostream>
#include <vector>

#include "util/binary_op.h"

namespace util {

template <class T>
class segment_tree {
   public:
    segment_tree(uint32_t n, T identity, std::function<void(T, T)> op)
        : m_n(n),
          m_identity(identity),
          m_buffer((binary_ceil(n) << 1) - 1, identity),
          m_op(op) {
    }

    /// @brief gets the size of internal buffer
    size_t buffer_size() const {
        return m_buffer.size();
    }

    size_t size() const {
        return m_n;
    }

    /// @brief update value at [idx] by [value]
    /// @param idx 0 <= idx < n
    /// @param value
    void update(uint32_t idx, T value) {
        assert(0 <= idx && idx < n);
        idx += m_n - 1;
        m_buffer[idx] = value;
        while (idx > 0) {
            idx = (idx - 1) >> 1;
            m_buffer[idx] = m_op(m_buffer[idx * 2 + 1], m_buffer[idx * 2 + 2]);
        }
    }

    T query(uint32_t idx_begin, uint32_t idx_end) const {
        assert(idx_begin < idx_end);
        assert(idx_end <= m_n);
        idx_begin += m_n - 1;
        idx_end += m_n - 1;
        T v_l(m_identity), v_r(m_identity);
        for (; idx_begin < idx_end; idx_begin >>= 1, idx_end >>= 1) {
            if (!(idx_begin & 1)) v_l = m_op(v_l, m_buffer[idx_begin++]);
            if (!(idx_end & 1)) v_r = m_op(m_buffer[--idx_end], v_r);
        }
        return m_op()
    }

   private:
    uint32_t m_n;
    T m_identity;
    std::vector<T> m_buffer;
    std::function<void(T, T)> m_op;
};
}  // namespace util