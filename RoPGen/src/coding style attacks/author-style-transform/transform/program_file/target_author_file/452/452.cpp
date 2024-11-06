#include <iostream>
#include <algorithm>
using namespace std;
int abc(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}
bool s (int x,int y) {
    if(abc(x) > abc(y)){
        return false;
    }else if(abc(x) < abc(y)){
        return true;
    }
}
int main() {
    int a;
    cin >> a;
    int n[1000];
    for(int i = 0;i < a;i++){
        cin >> n[i];
    }
    sort(n,n + a,s);
    for(int i = 0;i < a;i++){
        cout << n[i] << endl;
    }
    return 0;
}
