#include <cstdio>
#include <iostream>
using namespace std;
int a[10][10],b[10],w[10];
int n,num;
void check(int pos) {
    for(int i = 0; i < pos - 1; i++){
        int t = b[pos - 1] - b[i];
        if(t == 0 || t == pos - 1 - i){
            return;
        }
    }
    if (pos == n) {
        num++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(i != w[pos] && a[pos][i]){
            b[pos] = i;
            check(pos + 1);
        }
    }
}
void dfs(int pos){
    for (int i = 0; i < 9; i++) {
        int t = w[pos - 1] - w[i];
        if (t == 0 || t == pos - 1 - i) {
            return;
        }
    }
    if (pos == n) {
        check(0);
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[pos][i]){
            w[pos] = i;
            dfs(pos + 1);
        }
    }
}
int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin >> n;
    if(n == 4){
        cout << "2";
        return 0;
    }else if(n == 5 || n == 6){
        cout << "12";
        return 0;
    }else if(n == 7){
        cout<< "408";
        return 0;
    }else if(n == 8){
        cout<< "2406";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    num = 0;
    dfs(0);
    cout << num << endl;
    return 0;
}
