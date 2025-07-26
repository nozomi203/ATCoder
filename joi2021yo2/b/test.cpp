#include <iostream>
using namespace std;

int pow(int n) {
  if (n == 0) return 1;
  return n * pow(n - 1);
}
int main() { cout << pow(13) / pow(3) / pow(3) / pow(4) << endl; }