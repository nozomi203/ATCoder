#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class pos{
    public:
        int x;
        int y;
        pos(int x, int y){
            this->x = x;
            this->y = y;
        }

        pos operator +(pos p){
            pos sum(this->x + p.x, this->y + p.y);
            return sum;
        }
        pos operator -(pos p)
        {
            pos sum(this->x - p.x, this->y - p.y);
            return sum;
        }
        pos operator =(pos p){
            this->x = p.x;
            this->y = p.y;
            return *this;
        }

        bool operator ==(pos p){
            return (this->x == p.x) && (this->y == p.y);
        }
};

int main(){

    vector<pos> diff = {
        pos(0, 1),
        pos(0, -1),
        pos(1, 0),
        pos(-1, 0)
    };

    int H, W;
    bool find = false;
    pos curPos(0, 0);
    pos goal(0, 0);
    stack<pos> dest;
    vector<vector<char>> map;
    vector<vector<bool>> seen;


    cin >> H >> W;
    map.resize(H, vector<char>(W));
    seen.resize(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++){
        string s;
        cin >> s;
        for (int j = 0; j < W; j++){
            char c = s[j];
            if(c == 's'){
                dest.push(pos(i,j));
                seen[i][j] = true;
            }
            map[i][j] = c;
        }
    }


    while(dest.size() != 0 && !find){
        curPos = dest.top();
        dest.pop();
        for (int i = 0; i < 4; i++){
            pos tmp = curPos + diff[i];
            if(tmp.x < 0 || tmp.x >= H || tmp.y < 0 || tmp.y >= W){
                continue;
            }
            if(seen[tmp.x][tmp.y] == true){
                continue;
            }
            if(map[tmp.x][tmp.y] == 'g'){
                find = true;
                cout << "Yes" << endl;
                return 0;
            }else if(map[tmp.x][tmp.y] == '.'){
                dest.push(tmp);
                seen[tmp.x][tmp.y] = true;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}