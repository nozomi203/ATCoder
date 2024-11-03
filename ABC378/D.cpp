#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 H, W, K;
    cin >> H >> W >> K;
    vector<vector<bool>> obstacle(H, vector<bool>(W, false));
    for (s64 h = 0; h < H; ++h)
    {
        string S;
        cin >> S;
        for (s64 w = 0; w < W; ++w)
        {
            obstacle[h][w] = S[w] == '#' ? true : false;
        }
    }

    vector<vector<s64>> step(H, vector<s64>(W, 0));
    s64 ans = 0;
    for (s64 h = 0; h < H; ++h)
    {
        for (s64 w = 0; w < W; ++w)
        {
            if (obstacle[h][w])
            {
                continue;
            }

            struct Work
            {
                s64 h_prev;
                s64 w_prev;
                s64 h;
                s64 w;
                bool opened;
            };
            stack<Work> works;
            works.push(Work{ -1, -1, h, w, false });
            while (!works.empty())
            {
                Work& work = works.top();
                // 開封済み
                if (work.opened)
                {
                    step[work.h][work.w] = 0; // 足跡を消す
                    works.pop();
                    continue;
                }
                work.opened = true;

                // このマスの歩数
                s64 s = (work.h_prev >= 0 && work.w_prev >= 0)
                    ? step[work.h_prev][work.w_prev] + 1 // 以前の場所があったら歩数はその場所+1
                    : 1; // 以前の場所が無かったら1歩目
                step[work.h][work.w] = s;

                // 最大限進んだので答えを記録して終了
                if (s == K + 1)
                {
                    ++ans;
                    continue;
                }

                // 行先を展開
                constexpr pair<s64, s64> diffs[] = {
                    {-1,  0},
                    { 1,  0},
                    { 0, -1},
                    { 0,  1},
                };
                for (auto [dh, dw] : diffs)
                {
                    const s64 h_next = work.h + dh;
                    const s64 w_next = work.w + dw;
                    if (0 <= h_next     // 範囲チェック
                        && h_next < H   // 範囲チェック
                        && 0 <= w_next  // 範囲チェック
                        && w_next < W   // 範囲チェック
                        && !obstacle[h_next][w_next] // 障害物なし
                        && step[h_next][w_next] == 0 // 未踏
                        )
                    {
                        works.push(Work{ work.h, work.w, h_next, w_next, false });
                    }
                }
            }
        }
    }

    cout << ans << endl;
}