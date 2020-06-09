#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long A;
    float B;
    long long B100;

    cin >> A >> B;

    B100 = (long long)(B * 100);
    long long prod = A * B100;

    cout << (long long)(prod / 100 )<< endl;

    return 0;
}