#include<iostream>
#include<cstdio>
using namespace std;
int ans,n;
bool row[10],x1[20],x2[20],vis[20][20];
bool check(int i,int c){
    return !row[i] && !x1[i+c] && !x2[i-c+n] && vis[i][c]==false;
}
void dfs(int c,int time){
    if(c==n){
        if(time==1){
            dfs(0,2);
        }
        if(time==2){
            ans++;
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(check(i,c)){
            row[i]=x1[i+c]=x2[i-c+n]=true;
            vis[i][c]=true;
            dfs(c+1,time);
            vis[i][c]=false;
            row[i]=x1[i+c]=x2[i-c+n]=false;
        }
    }
}
int main(){
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    scanf("%d",&n);
    int a;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a);
            if(a==0){
                vis[i][j]=true;
            }
        }
    }
    dfs(0,1);
    printf("%d",ans);
    return 0;
}
