#include "util/common.h"

int main() {
    s64 H, W, N;
    cin >> H >> W >> N;
    struct Bar {
        s64 idx;
        s64 r;
        s64 c;
        s64 l;
    };
    vector<Bar> bars(N);
    for (s64 i = 0; i < N; ++i) {
        bars[i].idx = i;
        cin >> bars[i].r >> bars[i].c >> bars[i].l;
    }

    std::sort(bars.begin(), bars.end(), [](const auto& a, const auto& b) { return a.r < b.r; });
}