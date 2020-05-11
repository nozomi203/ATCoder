#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, W;
    vector<long long> w, v;
    vector<vector<long long>> value;
    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    value.resize(N, vector<long long>(W));
    for (int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i < W; i++){
        if(i >= w[0]){
            value[0][i] = v[0];
        }else{
            value[0][i] = 0;
        }
    }

    for (int i = 1; i < N; i++){

    }
}