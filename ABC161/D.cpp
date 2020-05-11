#include<iostream>
#include<queue>
using namespace std;

int main(){
    int K;
    cin >> K;
    queue<long long> q1;
    for (int i = 1; i < 10; i++){
        q1.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < K; i++){
        ans = q1.front();
        q1.pop();
        if(ans%10 != 0){
            q1.push(ans * 10 + (ans % 10) - 1);
        }
        q1.push(ans * 10 + (ans % 10));
        if(ans%10 != 9){
            q1.push(ans * 10 + (ans % 10) + 1);
        }
    }
    cout << ans << endl;
}