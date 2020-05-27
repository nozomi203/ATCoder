#include<iostream>

using namespace std;

int main(){
    int N, M;
    int result = 0;

    cin >> N >> M;
    if(N != 0){
        result += (N * (N - 1) /2);
    }
    if (M != 0)
    {
        result += (M * (M - 1) / 2);
    }

    cout << result << endl;
}