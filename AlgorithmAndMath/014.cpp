#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

void Factorize(s64 N)
{
    const s64 sqrtN = sqrt(N);
    for (s64 n = 2; n <= sqrtN; ++n)
    {
        if (N % n == 0)
        {
            cout << n << " ";
            Factorize(N / n);
            return;
        }
    }
    cout << N << endl;
}

int main()
{
    s64 N;
    cin >> N;
    Factorize(N);
}