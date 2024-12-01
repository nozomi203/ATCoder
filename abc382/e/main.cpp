#include "util/common.h"

int main() {
    s64 N, X;
    cin >> N >> X;
    vector<double> P(N + 1);
    for (s64 i = 1; i <= N; ++i) {
        cin >> P[i];
        P[i] /= 100.0;
    }

    // dp[i][j] = 1つのパックを開けたとき、i枚目までのカードの中でj枚がレアである確率
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
    dp[0][0] = 1.0;
    for (s64 i = 1; i <= N; ++i) {
        for (s64 j = 0; j <= N; ++j) {
            dp[i][j] = dp[i - 1][j] * (1.0 - P[i]);
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * P[i];
            }
        }
    }

    // dp2[i] = レアカードをi枚手に入れるまでパックを開封したとき、開封したパックの個数の期待値
    // dp2[0] = 0.0;
    // dp2[i] = 1 + dp2[i] * dp[N][0] + dp2[i - 1] * dp[N][1] + dp2[i - 2] * dp[N][2] + ...
    vector<double> dp2(X + 1, 0.0);
    for (s32 i = 1; i <= X; ++i) {
        for (s32 j = 1; j <= i; ++j) {
            dp2[i] += dp2[i - j] * (dp[N][j] / (1.0 - dp[N][0]));
        }
        dp2[i] += 1.0 / (1.0 - dp[N][0]);
    }
    cout << std::fixed << std::setprecision(30) << dp2[X] << endl;
}