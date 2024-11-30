#include "../../util.h"

int main() {
    s64 N;
    string S;
    cin >> N >> S;
    s64 ans{0};
    for (s64 i = 0; i < N - 2; ++i) {
        if (S[i] == '#' && S[i + 1] == '.' && S[i + 2] == '#') {
            ++ans;
        }
    }

    cout << ans << endl;
}