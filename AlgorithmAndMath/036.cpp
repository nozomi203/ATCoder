#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 A, B, H, M;
    cin >> A >> B >> H >> M;
    if (A > B)
    {
        swap(A, B);
    }
    double degH = 30 * (H + M / 60.0);
    double degM = 6 * M;
    double degDiff = abs(degH - degM);
    if (degDiff > 180.0f)
    {
        degDiff = 360.0 - degDiff;
    }
    constexpr double PI = 3.14159265358979;
    double radDiff = degDiff * (2 * PI / 360.0);

    double a = A * sin(radDiff);
    double b = B - A * cos(radDiff);
    cout << fixed << setprecision(20) << sqrt(a * a + b * b) << endl;
}