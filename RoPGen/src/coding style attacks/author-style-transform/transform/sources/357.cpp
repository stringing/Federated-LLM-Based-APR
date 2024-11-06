#include<iostream>
using namespace std;
char a[105][105];
int n,m,ans;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y){
    ans++;
    a[x][y]='.';
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&a[xx][yy]!='.'){
            dfs(xx,yy);
        }
    }
}
int main(){
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
                dfs(i,j);
            }
        }
    }
    cout<<ans/2;
    return 0;
}
