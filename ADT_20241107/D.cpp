#include <bits/stdc++.h>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 R, C;
    cin >> R >> C;
    vector<vector<char>> field(R + 1, vector<char>(C + 1));
    for (s64 r = 1; r <= R; ++r)
    {
        for (s64 c = 1; c <= C; ++c)
        {
            cin >> field[r][c];
        }
    }

    for (s64 r = 1; r <= R; ++r)
    {
        for (s64 c = 1; c <= C; ++c)
        {
            s64 num = field[r][c] - '0';
            if (1 <= num && num <= 9)
            {
                for (s64 r2 = 1; r2 <= R; ++r2)
                {
                    for (s64 c2 = 1; c2 <= C; ++c2)
                    {
                        if (field[r2][c2] == '#')
                        {
                            s64 dist = abs(r2 - r) + abs(c2 - c);
                            if (dist <= num)
                            {
                                field[r2][c2] = '.';
                            }
                        }
                    }
                }
                field[r][c] = '.';
            }
        }
    }

    for (s64 r = 1; r <= R; ++r)
    {
        for (s64 c = 1; c <= C; ++c)
        {
            cout << field[r][c];
        }
        cout << endl;
    }
}