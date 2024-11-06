#include <iostream>
using namespace std;
int main(){
  int n, a, b, dis, min;
  cin >> n >> a >> b;
  dis = n * a - 600;
  min = dis / (b - a);
  int min_int = int(min);
  if(min_int != min){
    min_int++;
  }
  cout << min_int;
  return 0;
}
