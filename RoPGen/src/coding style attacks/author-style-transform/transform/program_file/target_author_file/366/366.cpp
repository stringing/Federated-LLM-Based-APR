#include<bits/stdc++.h>
using namespace std;
int n,k,cow[30];
bool vis[30];
int minn = 99999999;
void dfs(int sum,int u){
    if(u == n-1) return;
    if(sum - k >= 0){
        minn = min(minn,sum-k);
        return;
    }
    dfs(sum,u+1);
    dfs(sum+cow[u],u+1);
    return;
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> cow[i];
    } 
    dfs(0,0);
    cout << minn;
    return 0;
}
