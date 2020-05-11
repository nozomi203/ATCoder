#include<iostream>
#include<vector>
using namespace std;

int check(char c[3]){
    int r = 0;
    int g = 0;
    int b = 0;
    for (int i = 0; i < 3; i++)
    {
        if(c[i]=='R'){
            r++;
        }else if(c[i]=='G'){
            g++;
        }else{
            b++;
        }
    }
    return r * g * b;

}

int main(){
    int N;
    string S;
    long long count = 0;
    long long count_not = 0;
    int r = 0, g = 0, b = 0;
    cin >> N;
    cin >> S;



    for (int i = 0; i < N; i++){
        switch(S[i]){
            case 'R':
                r++;
                break;
            case 'G':
                g++;
                break;
            case 'B':
                b++;
                break;
        }
    }

    for (int i = 0; i < N; i++){
        for (int k = 0; k < N; k++){
            if((i<k) && ((i + k)%2)==0){
                int j = (i + k) / 2;
                char c[] = {S[i], S[j], S[k]};
                if(check(c)!=0){
                    count_not++;
                }
            }
        }
    }

    count = r;
    count *= g;
    count *= b;
    count -= count_not;

    cout << count << endl;
}