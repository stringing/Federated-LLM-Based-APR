#include <iostream>
#include <algorithm>
using namespace std;
bool cmp (int x, int y){
    int a = 0;
    int b = 0;
    while(x){
        a += x % 10;
        x /= 10;
    }
    while(y){
        b += y % 10;
        y /= 10;
    }
    if (a == b){
        return x < y;
    }
    return a < b;
}
int main (){
    int n;
    cin >> n;
    int a[102];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
