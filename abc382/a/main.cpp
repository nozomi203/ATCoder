#include "util/common.h"

int main() {
    s64 N, D;
    string S;
    cin >> N >> D;
    cin >> S;
    s64 cnt{0};
    for (char c : S) {
        if (c == '.') ++cnt;
    }

    cout << cnt + D << endl;
}