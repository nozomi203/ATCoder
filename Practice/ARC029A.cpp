#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    int N;
    vector<int> t;
    int total;
    int total1 = 0;
    int total2 = 0;
    int m = 300;

    cin >> N;
    t.resize(N);
    for (int i = 0; i < N; i++){
        cin >> t[i];
    }

    for (int i = 0; i < pow(2, N); i++)
    {
        total1 = 0;
        total2 = 0;
        for (int j = 0; j < N; j++){

            if((i & (int)(pow(2, j))) != 0){
                total2 += t[j];
            }else{
                total1 += t[j];
            }
        }
        total = max(total1, total2);
        if(total < m){
            m = total;
        }
    }

    cout << m << endl;
}