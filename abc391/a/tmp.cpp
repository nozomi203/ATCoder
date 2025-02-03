#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
    map<string, string> dict = {
        {"N","S"},
        {"E","W"},
        {"W","E"},
        {"S","N"},
        {"NE","SW"},
        {"NW","SE"},
        {"SE","NW"},
        {"SW","NE"},
    };

    string D;
    cin >> D;
    cout << dict[D] << endl;
}
