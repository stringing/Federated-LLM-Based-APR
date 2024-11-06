#include <bits/stdc++.h>
int map[10][10], b[10], w[10];
int n, num;
void check(int pos) {
    for(int i = 0; i < pos - 1; i++) {
        int judge = b[pos - 1] - b[i];
        if(judge == 0 || judge == pos - 1 - i) {
            return;
        }
    }
    if(pos == n) {
        num++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(i != w[pos] && map[pos][i]) {
            b[pos] = i;
            check(pos + 1);
        }
    }
}
void dfs(int pos) {
    for(int i = 0; i < pos - 1; i++) {
        int judge = w[pos - 1] - w[i];
        if(judge == 0 || judge == pos -  1 - i) {
            return;
        }
    }
    if(pos == n) {
        check(0);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(map[pos][i]) {
            w[pos] = i;
            dfs(pos + 1);
        }
    }
}
int main () {
    freopen ("queen.in" , "r" , stdin);
    freopen ("queen.out" , "w" , stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    num = 0;
    dfs(0);
    cout << num << endl;
    return 0;
}
