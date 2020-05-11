#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N, M;
    int sumA = 0;
    int qualified = 0;
    vector<int> A;

    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
        sumA += A[i];
    }

    float bordar = (float)sumA / (4 * M);

    for (int i = 0; i < N; i++){
        if(A[i] >= bordar){
            qualified++;
        }
        if(qualified >= M){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}