#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int N, M; 
    int count = 0;
    vector<vector<int>> connect;
    vector<bool> seen;
    queue<int> dest;
    cin >> N >> M;
    connect.resize(N);
    seen.resize(N, false);

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        connect[a - 1].push_back(b - 1);
        connect[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < N; i++){
        if(seen[i]){
            continue;
        }
        dest.push(i);
        seen[i] = true;
        bool loop = false;
        while(dest.size() != 0){
            int next = dest.front();
            dest.pop();
            int connectCount = 0;
            for (int j = 0; j < connect[next].size(); j++){
                if(!seen[connect[next][j]]){
                    dest.push(connect[next][j]);
                    seen[connect[next][j]] = true;
                }else{
                    connectCount++;
                    if(connectCount > 1){
                        loop = true;
                    }
                }
            }
        }
        if(!loop){
            count++;
        }
    }

    cout << count << endl;
}