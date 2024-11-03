#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 H, W;
    cin >> H >> W;
    vector<vector<s64>> A(H + 1, vector<s64>(W + 1));
    vector<s64> sumH(H + 1, 0);
    vector<s64> sumW(W + 1, 0);
    for (s64 h = 1; h <= H; ++h)
    {
        for (s64 w = 1; w <= W; ++w)
        {
            s64 Ahw;
            cin >> Ahw;
            A[h][w] = Ahw;
            sumH[h] += Ahw;
            sumW[w] += Ahw;
        }
    }

    for (s64 h = 1; h <= H; ++h)
    {
        for (s64 w = 1; w <= W; ++w)
        {
            cout << sumH[h] + sumW[w] - A[h][w] << " ";
        }
        cout << endl;
    }
}