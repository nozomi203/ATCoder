#include "util/common.h"

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