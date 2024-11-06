#include<bits/stdc++.h>
using namespace std;
int fennv[15],kuangbao[15];
int ans = INT_MAX;
int n;
void dfs(int fen,int kuang,int k,int s){
    if(k == n) return;
    if(s != 0) ans = min(abs(kuang - fen),ans);
    dfs(fen,kuang,k+1,s);
    if(s == 0) fen = 1;
    dfs(fen*fennv[k],kuang+kuangbao[k],k+1,s+1);
    return;
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> fennv[i] >> kuangbao[i];
    }
    dfs(0,0,0,0);
    cout << ans;
    return 0;
}
