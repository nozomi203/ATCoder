#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct point{
    int x;
    int y;
};

int main(){

    point dir[] = {
        point{0, 1},
        point{0, -1},
        point{1, 0},
        point{-1, 0}
    };


    vector<vector<char>> map(10, vector<char>(10));

    for (int i = 0; i < 10; i++){
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++){
            map[i][j] = str[j];
        }
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){

            if(map[i][j] == 'x'){
                map[i][j] = 'o';
                vector<vector<bool>> seen(10, vector<bool>(10, false));
                stack<point> dest;
                int count = 0;
                for (int m = 0; m < 10; m++){
                    for (int n = 0; n < 10; n++){

                        if(map[m][n] == 'o' && !seen[m][n]){
                            dest.push(point{m, n});
                            count++;
                            while(dest.size() != 0){
                                point next = dest.top();
                                dest.pop();
                                for (int l = 0; l < 4; l++){
                                    point tmp{next.x + dir[l].x, next.y + dir[l].y};
                                    if (tmp.x < 0 || tmp.x >= 10 || tmp.y < 0 || tmp.y >= 10){
                                        continue;
                                    }
                                    if(seen[tmp.x][tmp.y]){
                                        continue;
                                    }
                                    if(map[tmp.x][tmp.y] == 'o'){
                                        seen[tmp.x][tmp.y] = true;
                                        dest.push(tmp);
                                    }
                                }
                            }
                            
                        }

                    }
                }
                if(count == 1){
                    cout << "YES" << endl;
                    return 0;
                }
                map[i][j] = 'x';
            }

        }
    }
    cout << "NO" << endl;
    return 0;
}