#include <bits/stdc++.h>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

struct Vec2
{
    s64 x;
    s64 y;
    s64 Cross(const Vec2& other)
    {
        return y * other.x - x * other.y;
    }
    Vec2 operator+(const Vec2& other) const
    {
        return Vec2{ x + other.x, y + other.y };
    }
    Vec2 operator-(const Vec2& other) const
    {
        return Vec2{ x - other.x, y - other.y };
    }
};

int main()
{
    Vec2 A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    Vec2 AB = B - A;
    Vec2 BC = C - B;
    Vec2 CD = D - C;
    Vec2 DA = A - D;
    array<s64, 4> cross = {
        AB.Cross(BC),
        BC.Cross(CD),
        CD.Cross(DA),
        DA.Cross(AB)
    };
    cout << (all_of(cross.begin(), cross.end(), [](const auto& elem) {return elem <= 0;}) ? "Yes" : "No") << endl;
}