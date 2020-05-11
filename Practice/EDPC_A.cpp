#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    vector<int> h;
    vector<long long> cost;

    cin >> N >> K;
    h.resize(N);
    cost.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
        cost[i] = 1LL << 60;
    }

    cost[0] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= K; j++){
            if(i-j >= 0){
                cost[i] = min(cost[i], cost[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }

    cout << cost[N - 1] << endl;
}