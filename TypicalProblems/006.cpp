#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    // nex[i][c] = i文字目以降に現れる文字cの最小インデックス
    vector<vector<s64>> nex(N, vector<s64>(26, N));
    nex[N - 1][S.back() - 'a'] = N - 1;
    for (s64 idx = N - 2; idx >= 0; --idx)
    {
        for (char c = 'a';c <= 'z'; ++c)
        {
            char cIdx = c - 'a';
            nex[idx][cIdx] = nex[idx + 1][cIdx];
        }
        nex[idx][S[idx] - 'a'] = idx;
    }

    s64 prevIdx = -1;
    s64 remain = K;
    while (remain > 0)
    {
        for (char c = 'a';c <= 'z'; ++c)
        {
            char cIdx = c - 'a';
            if (nex[prevIdx + 1][cIdx] <= N - remain)
            {
                cout << c;
                prevIdx = nex[prevIdx + 1][cIdx];
                --remain;
                break;
            }
        }
    }
    cout << endl;
}