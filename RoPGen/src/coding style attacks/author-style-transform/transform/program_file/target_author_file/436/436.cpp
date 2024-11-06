#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#define bug cout<<"bug"<<endl
#define ll long long
#define inf 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int n,m;
char a[105][105];
int b[105][105];
vector<int> ver[10000];
vector<int> ver1[10000];
vector<int> ver2[10000];
int x[10000],y[10000];
int top=1;
int dfn[10000],low[10000];
int tot=1;
int zhan[10000];
int topzhan=1;
int flag[10000];
int cnt=0;
int sum1[10000];
int sum2[10000];
int f[10000];
int flag1=0;
void tarjan(int u){
    dfn[u]=tot,low[u]=tot;
    tot++;
    zhan[topzhan++]=u;
    flag[u]=1;
    for(int i=0;i<ver[u].size();i++){
        int v=ver[u][i];
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(flag[v]==1){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        cnt++;
        if(u==1){
            flag1=cnt;
        }
        while(1){
            int x=zhan[topzhan-1];
            topzhan--;
            flag[x]=0;
            sum1[x]=cnt;
            if(x==u){
                break;
            }
        }
    }
}
int dfs(int u){
    
    
    
    int maxx=sum2[u];
    
    
    
    
    
    return maxx;
}
int main(){
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='*'){
                num++;
            }
        }
    }
    int tot=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=tot;
            tot++;
        }
    }
    int t1,t2;
        
    for(int i=1;i<=num;i++){
        cin>>t1>>t2;
        t1++,t2++;
        x[top]=t1;
        y[top]=t2;
        top++;
    }
    top=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t=b[i][j];
            if(a[i][j]<='9'&&a[i][j]>='1'){
                if(i!=n){
                    if(a[i+1][j]!='#'){
                        int tt=b[i+1][j];
                        ver[t].push_back(tt);
                        if(a[i+1][j]=='.') ver1[t].push_back(0);
                        else ver1[t].push_back(a[i+1][j]-'0');
                    }
                }
                if(j!=m){
                    if(a[i][j+1]!='#'){
                        int tt=b[i][j+1];
                        ver[t].push_back(tt);
                        if(a[i][j+1]=='.') ver1[t].push_back(0);
                        else ver1[t].push_back(a[i][j+1]-'0');
                    }
                }
            }
            if(a[i][j]=='*'){
                int xx=x[top],yy=y[top];
                top++;
                if(a[xx][yy]=='#'){
                    continue;
                }
                int tt=b[xx][yy];
                ver[t].push_back(tt);
                if(a[xx][yy]=='*') ver1[t].push_back(0);
                else ver1[t].push_back(a[xx][yy]-'0');
                if(i!=n){
                    if(a[i+1][j]!='#'){
                        int tt=b[i+1][j];
                        ver[t].push_back(tt);
                        if(a[i+1][j]=='.') ver1[t].push_back(0);
                        else ver1[t].push_back(a[i+1][j]-'0');
                    }
                }
                if(j!=m){
                    if(a[i][j+1]!='#'){
                        int tt=b[i][j+1];
                        ver[t].push_back(tt);
                        if(a[i][j+1]=='.') ver1[t].push_back(0);
                        else ver1[t].push_back(a[i][j+1]-'0');
                    }
                }
            }
        }
    }
    tarjan(1);
    for(int i=1;i<=b[n][m];i++){
        int u=i;
        for(int j=0;j<ver[u].size();j++){
            int v=j;
            if(sum1[u]==sum1[v]){
                sum2[sum1[u]]+=ver1[u][j];
            }
            else{
                ver2[sum1[u]].push_back(sum1[v]);
            }
        }
    }
    int ans=dfs(flag1);
    ans+=(a[1][1]-'0');
    cout<<ans<<"\n";
    return 0;
}
