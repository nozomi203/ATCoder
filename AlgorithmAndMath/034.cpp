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
    s64 N;
    cin >> N;
    vector<Vector2> vecs(N);
    for (s64 n = 0; n < N; ++n)
    {
        cin >> vecs[n].x >> vecs[n].y;
    }
    double minDist = numeric_limits<double>::max();
    for (s64 i = 0; i < N - 1; ++i)
    {
        for (s64 j = i + 1; j < N; ++j)
        {
            double dist = (vecs[i] - vecs[j]).Length();
            minDist = min(minDist, dist);
        }
    }
    cout << fixed << setprecision(20) << minDist << endl;
}