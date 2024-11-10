#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 H, W;
    cin >> H >> W;

    atcoder::dsu dsu((H + 1) * (W + 1));
    vector<vector<bool>> red(H + 1, vector<bool>(W + 1, false));

    s64 Q;
    cin >> Q;
    vector<bool> answers;
    for (s64 q = 0; q < Q; ++q)
    {
        s64 val;
        cin >> val;
        if (val == 1)
        {
            s64 r, c;
            cin >> r >> c;
            red[r][c] = true;
            constexpr pair<s64, s64> diffs[] = {
                {1, 0},
                {-1,0},
                {0, 1},
                {0, -1},
            };
            s64 idx = W * r + c;
            for (const auto& [dr, dc] : diffs)
            {
                s64 r2 = r + dr;
                s64 c2 = c + dc;
                if (1 <= r2 && r2 <= H && 1 <= c2 && c2 <= W && red[r2][c2])
                {
                    s64 idx2 = W * r2 + c2;
                    dsu.merge(idx, idx2);
                }
            }
        }
        else {
            s64 ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if (!red[ra][ca] || !red[rb][cb])
            {
                answers.push_back(false);
            }
            else {
                s64 idxa = W * ra + ca;
                s64 idxb = W * rb + cb;
                answers.push_back(dsu.same(idxa, idxb));
            }
        }
    }

    for (auto answer : answers)
    {
        cout << (answer ? "Yes" : "No") << endl;
    }
}