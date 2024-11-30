#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    string N;
    cin >> N;
    vector<s64> counts(10);
    for (char n : N)
    {
        ++counts[n - '0'];
    }

    cout << ((counts[1] == 1 && counts[2] == 2 && counts[3] == 3) ? "Yes" : "No") << endl;
}