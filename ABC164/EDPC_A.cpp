#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    vector<int> h;
    vector<int> cost;

    cin >> N;
    h.resize(N);
    cost.resize(N);
    for (int i = 0; i < N; i++){
        cin >> h[i];
    }

    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);

    for (int i = 2; i < N; i++){
        cost[i] = min(cost[i - 1] + abs(h[i] - h[i - 1]), cost[i - 2] + abs(h[i] - h[i - 2]));
        cout << "HOGE" << endl;
    }

    cout << cost[N - 1] << endl;
}