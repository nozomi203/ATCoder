#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    int N, M;
    int result = 0;
    vector<vector<int>> friends;
    cin >> N >> M;
    friends.resize(N);
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        friends[x - 1].push_back(y - 1);
        friends[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < pow(2, N); i++){
        int count = 0;
        bool good = true;
        for (int j = 0; j < N; j++){
            if((i & (int)pow(2, j)) != 0){
                count++;
                for (int k = 0; k < friends[j].size(); k++){
                    if((i & (int)pow(2, friends[j][k])) == 0){
                        good = false;
                        break;
                    }
                }
            }
            if(!good){
                break;
            }
        }
        if(good){
            result = max(result, count);
        }
    }

    cout << result << endl;
}