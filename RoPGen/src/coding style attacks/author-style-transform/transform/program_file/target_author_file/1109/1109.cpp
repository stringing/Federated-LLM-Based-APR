#include <iostream>
#include <algorithm>
using namespace std;
int sum(int m){
    int s = 0;
    while(m){
        s += m % 10;
        m /= 10;
    }
    return s;
}
int main(){
    int n;
    cin >> n;
    int x[10001];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x , x + n , sum);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    return 0;
}
