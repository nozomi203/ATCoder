#include<iostream>

using namespace std;

int main(){
    long long X;
    cin >> X;
    int n500 = X / 500;
    X = X - 500 * n500;
    int n5 = X / 5;

    long long h = n500 * 1000 + n5 * 5;

    cout << h << endl;
}