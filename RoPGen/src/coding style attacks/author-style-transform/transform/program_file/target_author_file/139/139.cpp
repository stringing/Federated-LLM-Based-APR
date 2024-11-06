#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
using namespace std;
typedef pair<int,int> PII;
const int N=10005,M=21000,INF=0x3f3f3f3f;
int n,m;
string a[N];
int e[M],ne[M],h[N],idx;
int new_h[N],new_e[M],new_ne[M],new_idx;
map<int,int> mp;
int times=0;
int dfn[N],low[N];
int scc_cnt=0;
int sccno[N],w[N];
set<int> scc[N];
set<PII> vis;
stack<int> S;
int f[N];
inline void c_plus(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
inline int c(int x,int y){
    return m*x+y+1;
}
inline void init(){
    idx=0;
    memset(h,-1,sizeof(h));
}
inline void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
inline void new_init(){
    new_idx=0;
    memset(new_h,-1,sizeof(new_h));
}
inline void new_add(int a,int b){
    new_e[new_idx]=b;
    new_ne[new_idx]=new_h[a];
    new_h[a]=new_idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++times;
    S.push(u);
    for (int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if (dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if (!sccno[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (low[u]==dfn[u]){
        scc_cnt++;
        while (true){
            int x=S.top();
            S.pop();
            scc[scc_cnt].insert(x);
            sccno[x]=scc_cnt;
            w[scc_cnt]+=mp[x];
            if (x==u){
                break;
            }
        }
    }
}
int dfs(int u){
    if (f[u]!=-1){
        return f[u];
    }
    int res=0;
    for (int i=new_h[u];~i;i=new_ne[i]){
        int v=new_e[i];
        res=max(res,dfs(v));
    }
    return f[u]=res+w[sccno[u]];
}
int main(){
    c_plus();
    init();
    cin>>n>>m;
    _for(i,0,n){
        cin>>a[i];
    }
    int ex,ey;
    cin>>ex>>ey;
    _for(i,0,n){
        _for(j,0,m){
            if (a[i][j]=='#'){
                mp[c(i,j)]=-INF;
                continue;
            }
            if (a[i][j]=='*'){
                add(c(i,j),c(ex,ey));
                mp[c(i,j)]=0;
            }
            if (i!=0){
                if (a[i-1][j]!='#'){
                    add(c(i-1,j),c(i,j));
                }
            }
            if (j!=0){
                if (a[i][j-1]!='#'){
                    add(c(i,j-1),c(i,j));
                }
            }
            if (!mp.count(c(i,j))){
                mp[c(i,j)]=a[i][j]-'0';
            }
        }
    }
    int ncnt=n*m+1;
    _for(i,1,ncnt){
        if (!dfn[i] && mp[i]!=-INF){
            tarjan(i);
        }
    }
    new_init();
    int first_id=sccno[1];
    _for(u,1,ncnt){
        for (int i=h[u];~i;i=ne[i]){
            int v=e[i];
            if (sccno[u]!=sccno[v] && !vis.count({sccno[u],sccno[v]})){
                vis.insert({sccno[u],sccno[v]});
                new_add(sccno[u],sccno[v]);
            }
        }
    }
    memset(f,-1,sizeof(f));
    int ans=dfs(first_id);
    cout<<ans<<endl;
    return 0;
}
