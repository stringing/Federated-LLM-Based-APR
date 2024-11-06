#include <bits/stdc++.h>
using namespace std;
int ans = 0,n;
int a[11][11];
bool row[10],x1[20],x2[20];
bool check(int i,int c)
{
    return a[i][c]&&!row[i]&&!x1[i+c]&&!x2[i-c+8];
}
void dfs(int c,int p){
    if(p==0){
        if(c==7){
            dfs(0,p+1);
            return ;
        }
        for(int i=0;i<8;i++){
            if(check(i,c)){
                row[i]=x1[i+c]=x2[i-c+8]=true;
                dfs(c+1,p);
                row[i]=x1[i+c]=x2[i-c+8]=false;
            }
        }
    }else{
        memset(row,0,sizeof row);
        memset(x1,0,sizeof x1);
        memset(x2,0,sizeof x2);
        if(c==7){
            ans++;
            return ;
        }
        for(int i=0;i<8;i++){
            if(check(i,c)){
                row[i]=x1[i+c]=x2[i-c+8]=true;
                dfs(c+1,p);
                row[i]=x1[i+c]=x2[i-c+8]=false;
            }
        }
    }
    
}
int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;    
}
