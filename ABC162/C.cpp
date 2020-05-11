#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main(){

    int K;
    cin >> K;
    int sum = 0;
    for (int i = 1; i <= K; i++){
        for (int j = 1; j <= K; j++){
            for (int k = 1; k <= K; k++){
                sum += gcd(gcd(i, j), k);
            }
        }
    }

    cout << sum << endl;
}