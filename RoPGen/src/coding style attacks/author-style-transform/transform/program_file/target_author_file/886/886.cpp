#include <bits/stdc++.h>
using namespace std;
bool vis[11][11];
int n,gt,ans=0;
bool row[10],x1[20],x2[20];
bool row2[10],x3[20],x4[20];
bool check(int c,int i){
    return !row[i]&&!x1[c+i]&&!x2[c-i+n]&&vis[i][c];
}
bool check2(int c,int i){
    return !row2[i]&&!x3[c+i]&&!x4[c-i+n]&&vis[i][c];
}
void dfs(int x,int type){
    if(x==n){
        if(type==1)dfs(0,2);
        else ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(type==1){
            if(check(x,i)){
                row[i]=x1[x+i]=x2[x-i+n]=1;
                vis[i][x]=0;
                dfs(x+1,type);
                vis[i][x]=1;
                row[i]=x1[x+i]=x2[x-i+n]=0;
            }
        }
        else{
            if(check2(x,i)){
                row[i]=x1[x+i]=x2[x-i+n]=1;
                vis[i][x]=0;
                dfs(x+1,type);
                vis[i][x]=1;
                row[i]=x1[x+i]=x2[x-i+n]=0;
            }
            
        }
    }
}
int main(){
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>gt;
            if(gt)vis[i][j]=1;
        }
    dfs(0,1);
    cout<<ans;
    return 0;
}

