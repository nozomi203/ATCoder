#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    int N;
    long long mul = 1;
    vector<long long> A;
    bool hasZero = false;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++){
        long long n;
        cin >> n;
        if(n == 0){
            hasZero = true;
        }
        A[i] = n;
    }

    if(hasZero){
        cout << 0 << endl;
        return 0;
    }else{
        for (int i = 0; i < N; i++){
            if(A[i] > (1000000000000000000/mul)){
                cout << -1 << endl;
                return 0;
            }
            mul *= A[i];
        }
        cout << mul << endl;
    }
}