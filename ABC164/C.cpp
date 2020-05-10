#include<iostream>
#include<map>
using namespace std;

int main(){
    int N;
    int count = 0;
    map<string, bool> collection{};
    cin >> N;
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(!collection[s]){
            count++;
            collection[s] = true;
        }
    }
    cout << count << endl;
}