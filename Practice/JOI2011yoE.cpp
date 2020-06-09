#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pos{
    int x;
    int y;
};
pos dir[] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int main(){
    int H, W, N;
    int time = 0;
    vector<vector<char>> map;
    vector<vector<int>> depth;
    vector<pos> factories;
    queue<pos> dest;

    cin >> H >> W >> N;
    map.resize(H, vector<char>(W));
    depth.resize(H, vector<int>(W, -1));
    factories.resize(N);

    for (int i = 0; i < H; i++){
        string str;
        cin >> str;
        for (int j = 0; j < W; j++){
            char c = str[j];
            if(c == 'S'){
                dest.push({i, j});
                depth[i][j] = 0;
            }
            map[i][j] = c;
        }
    }

    for (int i = 1; i <= N; i++){
        bool find = false;
        while(!find){
            pos now = dest.front();
            dest.pop();
            for (int j = 0; j < 4; j++){
                pos next = {now.x + dir[j].x, now.y + dir[j].y};
                if(next.x < 0 || H <= next.x || next.y < 0 || W <= next.y){
                    continue;
                }
                if(map[next.x][next.y] == 'X'){
                    continue;
                }
                if(depth[next.x][next.y] != -1){
                    continue;
                }
                if(map[next.x][next.y] == (i + '0')){
                    find = true;
                    time += (depth[now.x][now.y] + 1);
                    queue<pos>().swap(dest);
                    depth.clear();
                    depth.resize(H, vector<int>(W, -1));
                    dest.push(next);
                    depth[next.x][next.y] = 0;

                    break;
                }
                dest.push(next);
                depth[next.x][next.y] = depth[now.x][now.y] + 1;
            }
        }
    }
    cout << time << endl;
}