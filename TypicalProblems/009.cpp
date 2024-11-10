#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

static constexpr double kPi = 3.141592653589793238;

struct Vec2
{
    double x;
    double y;
    Vec2 operator+(const Vec2 &other) const
    {
        return Vec2{x + other.x, y + other.y};
    }
    Vec2 operator-(const Vec2 &other) const
    {
        return Vec2{x - other.x, y - other.y};
    }
    Vec2 operator/(double other) const
    {
        return Vec2{x / other, y / other};
    }
    double Length() const
    {
        return sqrt(x * x + y * y);
    }
    Vec2 Normalize() const
    {
        return *this / Length();
    }
    double Angle() const
    {
        Vec2 n = Normalize();
        return std::copysign(std::acos(n.x), std::asin(n.y)) * 180.0 / kPi;
    }
};

int main()
{
    s64 N;
    cin >> N;

    double ans{0.0};
    vector<Vec2> points(N + 1);
    for (s64 i = 1; i <= N; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }
    vector<std::pair<Vec2, double>> vecs;
    vecs.reserve(N - 1);
    for (s64 i = 1; i <= N; ++i)
    {
        vecs.clear();
        for (s64 j = 1; j <= N; ++j)
        {
            if (i == j)
            {
                continue;
            }

            Vec2 v = (points[j] - points[i]);
            vecs.emplace_back(std::pair{v, v.Angle()});
        }
        // 偏角の昇順にソート
        std::sort(vecs.begin(), vecs.end(), [](const auto &l, const auto &r)
                  { return l.second < r.second; });

        for (auto itr = vecs.begin(); itr != vecs.end(); ++itr)
        {
            const auto &[vec, angle] = *itr;
            double anchor = angle > 0.0 ? angle - 180.0 : angle + 180.0;
            auto itr2 = std::lower_bound(vecs.begin(), vecs.end(), anchor, [](auto &elem, double anchor)
                                         { return elem.second < anchor; });
            double angle1 = std::abs(angle - itr2->second);
            if (angle1 > 180.0)
            {
                angle1 -= 180.0;
            }
            double angle2 = std::abs(angle - std::next(itr2)->second);
            if (angle2 > 180.0)
            {
                angle2 -= 180.0;
            }
            ans = max(ans, max(angle1, angle2));
        }
    }

    cout << ans << endl;
}