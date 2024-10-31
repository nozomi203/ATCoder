#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

template <typename T>
struct Vector2
{
    T x;
    T y;

    T Dot(const Vector2 &other) const
    {
        return x * other.x + y * other.y;
    }
    T Length() const
    {
        return sqrt(LengthSquare());
    }
    T LengthSquare() const
    {
        return x * x + y * y;
    }
    Vector2 Normalize() const
    {
        T length = Length();
        return Vector2{x / length, y / length};
    }
    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2{x + other.x, y + other.y};
    }
    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2{x - other.x, y - other.y};
    }
    Vector2 operator*(double d) const
    {
        return Vector2{d * x, d * y};
    }
};

int main()
{
    Vector2<s64> v1, v2;
    s64 r1, r2;
    cin >> v1.x >> v1.y >> r1;
    cin >> v2.x >> v2.y >> r2;

    // r1 <= r2を保証
    if (r1 > r2)
    {
        swap(r1, r2);
        swap(v1, v2);
    }

    const s64 distSquare = (v1 - v2).LengthSquare();
    s64 ans = 0;
    if (distSquare < (r2 - r1) * (r2 - r1))
    {
        ans = 1;
    }
    else if (distSquare == (r2 - r1) * (r2 - r1))
    {
        ans = 2;
    }
    else if (distSquare == (r2 + r1) * (r2 + r1))
    {
        ans = 4;
    }
    else if (distSquare > (r2 + r1) * (r2 + r1))
    {
        ans = 5;
    }
    else
    {
        ans = 3;
    }

    cout << ans << endl;
}