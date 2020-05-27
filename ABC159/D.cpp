#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){

    int N;
    vector<int> A;
    map<long long, long long> numCount;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
        if(numCount.count(A[i]) == 0){
            numCount[A[i]] = 1;
        }else{
            numCount[A[i]]++;
        }
    }

    long long ans_full = 0;
    for (auto iter = numCount.begin(); iter != numCount.end(); iter++){
        long long n = iter->second;
        long long add = n * (n - 1) / 2;
        ans_full += add;
    }

    for (int i = 0; i < N; i++){
        long long ans = ans_full - numCount[A[i]] + 1;

        cout << ans << endl;
    }
}