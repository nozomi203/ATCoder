#include <bits/stdc++.h>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, M;
    cin >> N >> M;
    vector<std::pair<s64/*index*/, s64/*score*/>> A(M);
    for (s64 m = 0; m < M; ++m)
    {
        A[m].first = m;
        cin >> A[m].second;
    }
    std::sort(A.begin(), A.end(), [](const auto& l, const auto& r) { return l.second > r.second;});

    s64 maxScore = 0;
    s64 maxIdx = 0;
    // scoreToAdd(n, i) = n番目のプレイヤーがi問追加で回答したときの加点
    vector<vector<s64>> scoreToAdd(N + 1, vector<s64>(M + 1, 0));
    for (s64 n = 1; n <= N; ++n)
    {
        scoreToAdd[n][0] += n;
        string S;
        cin >> S;
        s64 addCnt = 0;
        for (s64 i = 0; i < M; ++i)
        {
            if (S[A[i].first] == 'o')
            {
                scoreToAdd[n][0] += A[i].second;
            }
            else {
                ++addCnt;
                scoreToAdd[n][addCnt] += A[i].second;
            }
        }
        if (scoreToAdd[n][0] > maxScore)
        {
            maxScore = scoreToAdd[n][0];
            maxIdx = n;
        }
    }

    for (s64 n = 1; n <= N; ++n)
    {
        if (n == maxIdx)
        {
            cout << 0 << endl;
            continue;
        }

        s64 score{ 0 };
        for (s64 i = 0; i <= M; ++i)
        {
            score += scoreToAdd[n][i];
            if (score > maxScore)
            {
                cout << i << endl;
                break;
            }
        }
    }
}