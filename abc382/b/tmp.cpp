#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
    s64 N, D;
    string S;
    cin >> N >> D;
    cin >> S;
    s64 cnt{0};
    for (s64 i = S.size() - 1; i >= 0; --i) {
        if (S[i] == '@') {
            ++cnt;
            S[i] = '.';
            if (cnt == D) {
                break;
            }
        }
    }

    cout << S << endl;
}
