#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> h;
int detectDivision(){
    int segment = 0;
    bool connect = false;
    for (int i = 0; i < N; i++){
        if(h[i]>0){
            if(!connect){
                connect = true;
                segment++;
            }
        }else{
            if(connect){
                connect = false;
            }
        }
        h[i]--;
    }
    return segment;
}

int main(){
    int max = 0;
    int result = 0;
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; i++){
        cin >> h[i];
        if(max < h[i]){
            max = h[i];
        }
    }
    for (int i = 0; i < max; i++){
        result += detectDivision();
    }

    cout << result << endl;
}