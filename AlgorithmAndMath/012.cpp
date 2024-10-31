#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

template <typename Int>
void ForeachPrime(Int max, function<bool /* break flag */ (remove_const_t<Int>)> func)
{
    vector<bool> p(max + 1, true);

    for (Int n = 2; n <= max; ++n)
    {
        if (!p[n])
        {
            continue;
        }
        Int mul = n * 2; // 倍数
        while (mul <= max)
        {
            p[mul] = false;
            mul += n;
        }
    }

    for (Int n = 2; n <= max; ++n)
    {
        if (p[n])
        {
            if (func(n))
            {
                break;
            }
        }
    }
}

int main()
{
    s64 N;
    cin >> N;

    bool isP = true;
    const s64 sqrtN = static_cast<s64>(sqrt(N));
    ForeachPrime(sqrtN, [N, &isP](s64 p)
                 {
        if(N % p == 0)
        {
            isP = false;
            return true;
        } 
        return false; });

    cout << (isP ? "Yes" : "No") << endl;
}