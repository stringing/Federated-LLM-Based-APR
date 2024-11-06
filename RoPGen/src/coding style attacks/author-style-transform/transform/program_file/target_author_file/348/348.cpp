#include<bits/stdc++.h>
using namespace std;

int n,a[15][15],ans;
int row1[1000], x1[2000], x2[2000];
int row2[1000], x3[2000], x4[2000];

bool check(int x,int y,int k){
    if(k){
        return !row2[y] && !x3[x + y] && !x4[x - y + n];
    }
    else{
        return !row1[y] && !x1[x + y] && !x2[x - y + n];
    }
}


void dfs(int dep) { 
    if(dep >= n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(check(dep,i,0)){
            row1[i] = x1[dep + i] = x2[dep - i + n] = true;
            for(int j=0;j<n;j++){
                if(check(dep,j,1) && j != i){
                    row2[j] = x3[dep + j] = x4[dep - j + n] = true;
                    dfs(dep+1);
                    row2[j] = x3[dep + j] = x4[dep - j + n] = false;
                }
            }
            row1[i] = x1[dep + i] = x2[dep - i + n] = false;
        }
    }
}

int main(){
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
