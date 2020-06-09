#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long N;
    long long ans = 0;
    cin >> N;

    long long original = N;
    double rootN = sqrt(N);
    for (int i = 2; i <= rootN; i++){
        long long rest = 0;
        long long count = 0;
        while(rest == 0){
            rest = N % i;
            if(rest == 0){
                count++;
                N = N / i;
            }
        }
        ans += (long long)((-1 + sqrt(1 + 8 * count)) / 2);
    }
    if((N % original) == 0){
        ans++;
    }

    cout << ans << endl;
}