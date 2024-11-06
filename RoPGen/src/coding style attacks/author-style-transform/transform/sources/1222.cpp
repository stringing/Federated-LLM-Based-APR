#include<bits/stdc++.h>
using namespace std;
int n,k,cow[30];
bool vis[30];
int minn = 9999999999;
void dfs(int sum){
    if(sum > minn) return;
    if(n - k >= 0){
        min(minn,n-k);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(sum + cow[i]);
            vis[i] = false;
        }
    }
    return;
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> cow[i];
    } 
    dfs(0);
    cout << minn;
    return 0;
}
