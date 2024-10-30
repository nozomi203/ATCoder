#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 newBoxSize = -1;

    s64 N;
    cin >> N;

    multiset<s64, greater<s64>> toys;
    for (s64 n = 0; n < N; ++n)
    {
        s64 A;
        cin >> A;
        toys.insert(A);
    }
    multiset<s64, greater<s64>> boxes;
    for (s64 n = 0; n < N - 1; ++n)
    {
        s64 B;
        cin >> B;
        boxes.insert(B);
    }

    auto tItr = toys.cbegin();
    auto bItr = boxes.cbegin();
    bool hasNewBox = false;
    for (s64 n = 0; bItr != boxes.cend(); ++n)
    {
        s64 t = *tItr;
        s64 b = *bItr;

        if (b >= t)
        {
            ++tItr;
            ++bItr;
        }
        else if (!hasNewBox)
        {
            newBoxSize = t;
            hasNewBox = true;
            ++tItr;
        }
        else
        {
            newBoxSize = -1;
            break;
        }
    }

    if (!hasNewBox)
    {
        newBoxSize = *tItr;
    }

    cout << newBoxSize << endl;
}