#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long N;
    vector<long long> A, B;

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    long long bad = 0;

    for (int i = 0; i < N - 1;i++){
        for (int j = i + 1; i < N; i++){
            if((A[i] * A[j] + B[i] * B[j]) == 0){
                bad++;
            }
        }
    }

    long long ans = 
}