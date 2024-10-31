#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

struct Vector2
{
    double x;
    double y;

    double Dot(const Vector2 &other) const
    {
        return x * other.x + y * other.y;
    }
    double Length() const
    {
        return sqrt(x * x + y * y);
    }
    Vector2 Normalize() const
    {
        double length = Length();
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
    Vector2 a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    Vector2 bc = c - b;
    Vector2 ba = a - b;
    double dot = bc.Normalize().Dot(ba);
    if (dot < 0.0)
    {
        cout << fixed << setprecision(20) << ba.Length() << endl;
    }
    else if (dot <= bc.Length())
    {
        cout << fixed << setprecision(20) << (ba - bc.Normalize() * dot).Length() << endl;
    }
    else
    {
        cout << fixed << setprecision(20) << (a - c).Length() << endl;
    }
}