#include <iostream>
using namespace std;
int main(){
    long long n,a,b,dj,zj,m,min,min_int;
    cin >> n >> a >> b;
    dj = n * a;
    zj = dj - 600;
    m = b - a;
    min = zj / m;
    min_int = min;
    if(min_int != min){
      min_int++;
    }
   cout << min_int;
}
