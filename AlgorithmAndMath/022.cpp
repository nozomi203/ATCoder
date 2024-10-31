#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;
    double sumB{};
    for (s64 n = 0; n < N; ++n)
    {
        s64 B;
        cin >> B;
        sumB += B;
    }
    double sumR{};
    for (s64 n = 0; n < N; ++n)
    {
        s64 R;
        cin >> R;
        sumR += R;
    }
    double e = sumB / N + sumR / N;
    cout << fixed << setprecision(20) << e << endl;
}