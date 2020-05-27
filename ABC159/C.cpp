#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    int L;
    cin >> L;

    cout << fixed << setprecision(15) << (double)L*L*L/27 << endl;
}