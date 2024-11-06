#include <iostream>
#include <algorithm>
using namespace std;
int sum (int a) {
    int sum = 0;
    while (a) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
bool cmp (int x, int y) {
    if (sum(x) != sum(y)) {
        return sum(x) < sum(y);
    }
    return x < y;
}
int main(){
    int n, x[10000];
    cin >> n;
    for(int i = 0;i < n;i++){
       cin >> x[i];
        
    }
    sort(x, x + n);
    for(int i = 0;i < n;i++){
       cout << x[i] << " ";
    }
    return 0;

}
