#include <iostream>
using namespace std;
int main(){
  int n, a, b, c;
  cin >> n >> a >> b;
  c = b * (a - n);
  c = c - (600 / n);
  cout << c << endl;
  return 0;
}
