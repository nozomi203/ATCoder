#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    int N, M;
    vector<vector<int>> dest;
    queue<int> next;
    next.push(0);

    cin >> N >> M;
    dest.resize(N);

    vector<bool> seen(N, false);
    vector<int> info(N, false);
    seen[0] = true;

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        dest[a - 1].push_back(b - 1);
        dest[b - 1].push_back(a - 1);
    }

    while(!next.empty()){
        int now = next.front();
        next.pop();

        for (int i = 0; i < dest[now].size(); i++){
            if(!seen[dest[now][i]]){
                seen[dest[now][i]] = true;
                next.push(dest[now][i]);
                info[dest[now][i]] = now + 1;
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i < N; i++){
        cout << info[i] << endl;
    }
}