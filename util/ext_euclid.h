#include <concepts>
#include <type_traits>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <cassert>

/// @brief 拡張ユークリッドの互除法（ax + by = c の特殊解を求める）
/// @tparam int_type 任意の整数型
/// @param a xの係数(!=0)
/// @param b yの係数(!=0)
/// @param c 二元一次不定方程式の右辺
/// @param x_out 特殊解x
/// @param y_out 特殊解y
/// @return 特殊解が存在するか
template <std::signed_integral int_type>
bool ext_euclid(int_type a, int_type b, int_type c, int_type &x_out, int_type &y_out)
{
    assert(a != 0);
    assert(b != 0);
    // ensure a > 0
    const bool a_negative = a < 0;
    a = std::abs(a);
    // ensure b > 0
    const bool b_negative = b < 0;
    b = std::abs(b);

    // ensure a >= b
    const bool a_b_swap = a < b;
    if (a_b_swap)
    {
        std::swap(a, b);
    }

    const auto ext_euclid_internal = [](auto self, int_type a, int_type b, int_type &x_out, int_type &y_out)
    {
        if (b == 0)
        {
            x_out = 1;
            y_out = 0;
            return;
        }
        const auto r = a % b;
        const auto q = a / b;
        int_type x_out_tmp, y_out_tmp;
        self(self, b, r, x_out_tmp, y_out_tmp);
        x_out = y_out_tmp;
        y_out = x_out_tmp - q * y_out_tmp;
    };
    const auto gcd = std::gcd(a, b);
    if (c % gcd == 0)
    {
        ext_euclid_internal(ext_euclid_internal, a / gcd, b / gcd, x_out, y_out);
        if (a_negative)
        {
            std::negate(x_out);
        }
        if (b_negative)
        {
            std::negate(y_out);
        }
        if (a_b_swap)
        {
            std::swap(x_out, y_out);
        }
        x_out *= gcd;
        y_out *= gcd;
        return true;
    }
    return false;
}