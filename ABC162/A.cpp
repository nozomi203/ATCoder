#include<iostream>
using namespace std;

int main(){
    string N;
    cin >> N;
    cout << ((N[0] == '7' || N[1] == '7' || N[2] == '7') ? "Yes" : "No") << endl;
}