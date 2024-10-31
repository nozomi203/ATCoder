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

    const s64 sqrtN = static_cast<s64>(sqrt(N));
    for (s64 n = 1; n <= sqrtN; ++n)
    {
        if (N % n == 0)
        {
            cout << n << endl;
            s64 other = N / n;
            if (other != n)
            {
                cout << other << endl;
            }
        }
    }
}