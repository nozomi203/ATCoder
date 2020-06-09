#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pos{
    int x;
    int y;
};

int main(){

    int R, C;
    pos start, goal;
    vector<vector<char>> c;
    vector<vector<int>> depth;
    queue<pos> dest;
    pos dir[] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx;
    cin >> gy >> gx;
    start = {sx - 1, sy - 1};
    goal = {gx - 1, gy - 1};
    c.resize(R, vector<char>(C));
    depth.resize(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++){
        string str;
        cin >> str;
        for (int j = 0; j < C; j++){
            c[i][j] = str[j];
        }
    }
    dest.push(start);
    depth[start.y][start.x] = 0;
    while(dest.size() != 0){
        pos now = dest.front();
        dest.pop();
        if((now.x == goal.x) && (now.y == goal.y)){
            cout << depth[now.y][now.x] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++){
            pos next = {now.x + dir[i].x, now.y + dir[i].y};
            if((next.x < 0) || (next.x >= C) || (next.y < 0) || (next.y >= R)){
                continue;
            }
            if(depth[next.y][next.x] != -1){
                continue;
            }
            if(c[next.y][next.x] == '#'){
                continue;
            }
            dest.push(next);
            depth[next.y][next.x] = depth[now.y][now.x] + 1;
        }
    }
}