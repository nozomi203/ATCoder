#include<iostream>
#include<algorithm>
using namespace std;

bool isPalindrome(string s){
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    if(s == s_rev){
        return true;
    }else{
        return false;
    }
}
int main(){
    string S;
    cin >> S;
    int l = S.size();
    int l_div = (l - 1)/2;

    if(isPalindrome(S) && isPalindrome(S.substr(0,l_div)) && isPalindrome(S.substr(l_div + 1, l_div))){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}