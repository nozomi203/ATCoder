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

    double E = 0.0;

    for (s64 n = 0; n < N; ++n)
    {
        s64 P, Q;
        cin >> P >> Q;

        E += Q / static_cast<double>(P);
    }

    cout << fixed << setprecision(20) << E << endl;
}