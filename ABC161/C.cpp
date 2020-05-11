#include<iostream>
#include<cmath>
using namespace std;

int op(int N, int K){
    return abs(N - K);
}
int main(){
    long long N, K;
    cin >> N >> K;
    N = N % K;

    long long result = min(N, K - N);

    cout << result << endl;
}