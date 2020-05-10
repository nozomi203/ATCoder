#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int numT = ceil(float(C) / B);
    int numA = ceil(float(A) / D);

    if(numT <= numA){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}