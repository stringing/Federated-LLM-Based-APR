#include<bits/stdc++.h>
using namespace std;
int n, b,ans=-1;
int h[30];
void dfs(int dep,int sum) {
    if (dep == n) {
        if(sum>b&&sum-b<ans){
            ans=sum;
        }
        return;
    }
    for(int i=0;i<20;i++){
        dfs(dep + 1, sum+h[i]);
        dfs(dep + 1, sum);
    }
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    cin>>n>>b;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
