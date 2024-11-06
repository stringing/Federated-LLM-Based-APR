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
inline int read(){  int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int n,m;
struct node{
    int u;
    int v;
}zhan[100000];
vector<int> ver[100000];
vector<int> ver1[100000];
int dfn[100000],low[100000];
int tot=1;
int flag[10000];
int ans1=0,ans2=0;
int sumbian[10000];
int top=1;
int cnt=0;
void tarjan1(int u,int father){
    dfn[u]=tot,low[u]=tot;
    tot++;
    for(int i=0;i<ver[u].size();i++){
        int v=ver[u][i];
        if(dfn[v]==0){
            tarjan1(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                ans1++;
            }
        }
        else if(v!=father){
            low[u]=min(low[u],dfn[v]);
        }
    }
} 
void tarjan2(int u,int father){
    dfn[u]=tot,low[u]=tot;
    tot++;
    for(int i=0;i<ver[u].size();i++){
        int v=ver[u][i];
        if(v==father){
            continue;
        }
        zhan[top].u=u;
        zhan[top].v=v;
        top++;
        if(dfn[v]==0){
            tarjan2(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                cnt++;
                int flag=0;
                while(1){
                    int x=zhan[top-1].u;
                    int y=zhan[top-1].v;
                    top--;
                    ver1[cnt].push_back(x);
                    ver1[cnt].push_back(y);
                    if(flag==1) sumbian[cnt]++;
                    flag=1;
                    if(x==u&&y==v){
                        break;
                    }
                }
            }
        }
        else{
            low[u]=min(low[u],dfn[v]);
        }
    }
} 
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        x++,y++;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan1(i,i);
        }
    }
    cout<<ans1<<" ";
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    tot=1;
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan2(i,i); 
        }
    }
    for(int i=1;i<=cnt;i++){
        sort(ver1[i].begin(),ver1[i].end());
        ver1[i].erase(unique(ver1[i].begin(),ver1[i].end()),ver1[i].end());
        if(ver1[i].size()<sumbian[i]){
            ans2+=sumbian[i];
        }
    }
    cout<<ans2<<"\n";
    return 0;
}
