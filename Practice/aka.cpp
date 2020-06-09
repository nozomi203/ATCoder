#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

bool check_int(string str)
{
    
    for(int i = 0; i < str.length(); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.

  string line;
  stack<int> nums;
  cin >> line;

  vector<string> line_split = split(line, ' ');

  for(int i = 0; i < line_split.size(); i+=2){

    int x, y, z, result;

    string c = line_split[i];
    if(check_int(c)){
      nums.push(atoi(c.c_str()));
    }else if(c == "+"){
      if(nums.size() < 2){
        cout << "invalid" << endl;
        return 0;
      }
      x = nums.top();
      nums.pop();
      y = nums.top();
      nums.pop();
      result = x + y;
      nums.push(result);
      
    }else if(c == "-"){
      if(nums.size() < 2){
        cout << "invalid" << endl;
        return 0;
      }
      x = nums.top();
      nums.pop();
      y = nums.top();
      nums.pop();
      result = x - y;
      nums.push(result);
    }else if(c == "*"){
      if(nums.size() < 2){
        cout << "invalid" << endl;
        return 0;
      }
      x = nums.top();
      nums.pop();
      y = nums.top();
      nums.pop();
      result = x * y;
      nums.push(result);
    }else if(c == "++"){
      if(nums.size() < 1){
        cout << "invalid" << endl;
        return 0;
      }
      x = nums.top();
      nums.pop();
      result = x + 1;
      nums.push(result);
    }else if(c == "@"){
      if(nums.size() < 3){
        cout << "invalid" << endl;
        return 0;
      }
      x = nums.top();
      nums.pop();
      y = nums.top();
      nums.pop();
      z = nums.top();
      nums.pop();
      result = (x * y)+(y * z)+(z * x);
      nums.push(result);
    }else {
      cout << "invalid" << endl;
      return 0;
    }
  }

  if(nums.size() == 1){
    cout << nums.top() << endl;
  }else{
    cout << "invalid" << endl;
  }
  return 0;
}
