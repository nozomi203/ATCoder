#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

void get_answers(vector<s64>& values, vector<vector<s64>>& results, s64 max, s64 idx = 0) {
    if (idx == values.size()) {
        results.emplace_back(values);
        return;
    }
    for (s64 value = idx == 0 ? 1 : values[idx - 1] + 10; value + 10 * (values.size() - idx - 1) <= max; ++value) {
        values[idx] = value;
        get_answers(values, results, max, idx + 1);
    }
}

int main() {
    s64 N, M;
    cin >> N >> M;
    vector<s64> values(N, 1);
    for (s64 i = 1; i < N; ++i) values[i] = values[i - 1] + 10;
    vector<vector<s64>> results;
    get_answers(values, results, M);
    cout << results.size() << endl;
    for (const auto& result : results) {
        for (s64 i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1) cout << " ";
        }
        cout << endl;
    }
}
