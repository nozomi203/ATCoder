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
    int H, W;
    int nw = 0;
    int count = 0;
    vector<vector<char>> map;
    vector<vector<int>> depth;
    queue<pos> dest;
    cin >> H >> W;
    map.resize(H, vector<char>(W));
    depth.resize(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < W; j++){
            char c = str[j];
            if(c == '.'){
                nw++;
            }
            map[i][j] = str[j];
        }
    }
    dest.push({0, 0});
    depth[0][0] = 1;
    while(dest.size() != 0){
        pos now = dest.front();
        dest.pop();
        for (int i = 0; i < 4; i++){
            pos next = {now.x + dir[i].x, now.y + dir[i].y};
            if (next.x < 0 || H <= next.x || next.y < 0 || W <= next.y){
                continue;
            }
            if(map[next.x][next.y] == '#'){
                continue;
            }
            if(depth[next.x][next.y] != -1){
                continue;
            }

            if((next.x == H - 1) && (next.y == W - 1)){
                count++;
                int point = nw - depth[now.x][now.y] - 1;
                cout << point << endl;
                return 0;
            }
            count++;
            dest.push(next);
            depth[next.x][next.y] = depth[now.x][now.y] + 1;
        }
    }
    cout << -1 << endl;
    return 0;
}