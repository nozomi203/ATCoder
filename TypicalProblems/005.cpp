#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, B, K;
    cin >> N >> B >> K;
    vector<s64> C(K);
    // O(K)
    for (s64 k = 0; k < K; ++k)
    {
        cin >> C[k];
    }

    // Nの最大シフト数を求める O(N)
    const s64 maxShift = std::invoke([N]()
        {
            s64 shift = 0;
            s64 n = N;
            while (n > 1)
            {
                ++shift;
                n = n >> 1;
            }
            return shift;
        });

    constexpr s64 kMod = 1000000007;

    // O(logN)
    vector<s64> pow10rem(maxShift + 1, 0);
    pow10rem[0] = 10;
    for (s64 shift = 1; shift <= maxShift; ++shift)
    {
        pow10rem[shift] = (pow10rem[shift - 1] * pow10rem[shift - 1]) % B;
    }

    // O(B^2)
    const auto mul = [B, &pow10rem](const vector<s64>& in0, const vector<s64>& in1, s64 shift1)
        {
            vector<s64> out(B, 0);
            for (s64 r0 = 0; r0 < B; ++r0)
            {
                for (s64 r1 = 0; r1 < B; ++r1)
                {
                    s64 r = (r0 * pow10rem[shift1] + r1) % B;
                    out[r] += in0[r0] * in1[r1];
                    out[r] %= kMod;
                }
            }
            return out;
        };

    // dp[i][r] = cに含まれる数のみを使った2^i桁の数であって、Bで割ったときのあまりがrであるようなものの個数
    vector<vector<s64>> doubling(maxShift + 1, vector<s64>(B, 0));
    for (s64 c : C)
    {
        s64 r = c % B;
        doubling[0][r] += 1;
    }

    // initialize doubling O(B^2 * logN)
    for (s64 shift = 0; shift < maxShift; ++shift)
    {
        doubling[shift + 1] = mul(doubling[shift], doubling[shift], shift);
    }

    vector<s64> res(B, 0);
    res[0] = 1;
    for (s64 shift = 0; shift <= maxShift; ++shift)
    {
        if (N & (1LL << shift))
        {
            res = mul(res, doubling[shift], shift);
        }
    }

    cout << res[0] << endl;
}