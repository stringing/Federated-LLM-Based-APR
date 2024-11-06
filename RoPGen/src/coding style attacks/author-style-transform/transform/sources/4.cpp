#include <iostream>
using namespace std;
int ans=0,n;
int a[10][10];
bool row[2][10],x1[2][20],x2[2][20];
bool check(int c,int i,int color){
    return !row[color][i]&&!x1[color][c+i]&&!x2[color][c-i+n];
}
void dfs(int c,int color){
    if(c==n){
        if(color==0){
            dfs(0,color+1);
        }
        else{
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(check(c,i,color)&&a[i][c]!=0){
            row[color][i]=x1[color][c+i]=x2[color][c-i+n]=true;
            a[i][c]=0;
            dfs(c+1,color);
            a[i][c]=1;
            row[color][i]=x1[color][c+i]=x2[color][c-i+n]=false;
        }
    }
}

int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;    
}
