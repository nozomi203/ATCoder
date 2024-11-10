#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 Q;
    cin >> Q;
    vector<s64> height(Q + 1);
    queue<s64> plants;
    vector<s64> answers;
    for (s64 q = 0; q < Q; ++q)
    {
        s64 n;
        cin >> n;
        if (n == 1)
        {
            height[q + 1] = height[q];
            plants.push(q);
        }
        else if (n == 2)
        {
            s64 T;
            cin >> T;
            height[q + 1] = height[q] + T;
        }
        else if (n == 3)
        {
            s64 H;
            cin >> H;
            height[q + 1] = height[q];

            s64 ans = 0;
            while (!plants.empty())
            {
                if (height[q + 1] - height[plants.front() + 1] >= H)
                {
                    ++ans;
                    plants.pop();
                }
                else {
                    break;
                }
            }
            answers.push_back(ans);
        }
    }

    for (auto answer : answers)
    {
        cout << answer << endl;
    }
}