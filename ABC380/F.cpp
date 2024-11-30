#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

using Node = std::array <std::vector<s32>, 3>;
using Table = std::map<Node, bool>;

// nodeであらわされる状態のとき勝ち確か？
bool dfs(const Node& node, Table& dp)
{
    if (node[0].empty()) return false; // 出せるカードがないので負け

    // メモを参照
    if (auto itr = dp.find(node); itr != dp.end()) return itr->second;

    bool res{ false };

    for (s32 aIdx = 0; aIdx < node[0].size(); ++aIdx)
    {
        s32 a = node[0][aIdx];
        vector<s32> newA = node[0], newB = node[1], newC = node[2];

        newA.erase(newA.begin() + aIdx);
        newC.emplace_back(a);
        std::sort(newC.begin(), newC.end());

        // 何も取らん
        if (!dfs(Node({ newB, newA, newC }), dp)) res = true;

        // 何かとる
        for (s32 cIdx = 0; cIdx < newC.size(); ++cIdx)
        {
            if (newC[cIdx] >= a)break;
            vector<s32> newA2 = newA, newB2 = newB, newC2 = newC;
            newA2.emplace_back(newC2[cIdx]);
            newC2.erase(newC2.begin() + cIdx);
            std::sort(newA2.begin(), newA2.end());
            if (!dfs(Node({ newB2, newA2, newC2 }), dp)) res = true;
        }
    }
    return dp[node] = res;
}

int main()
{
    s32 N, M, L;
    cin >> N >> M >> L;
    vector<s32> A(N);
    for (s32 n = 0; n < N; ++n)cin >> A[n];
    vector<s32> B(M);
    for (s32 m = 0; m < M; ++m)cin >> B[m];
    vector<s32> C(L);
    for (s32 l = 0; l < L; ++l)cin >> C[l];

    Table dp;
    cout << (dfs(Node({ A,B,C }), dp) ? "Takahashi" : "Aoki") << endl;
}