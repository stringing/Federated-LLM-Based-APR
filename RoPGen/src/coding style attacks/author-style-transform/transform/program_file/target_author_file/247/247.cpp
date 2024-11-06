#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<set>
#define _for(i,a,b) for (int i=(a);i<(b);i++)
using namespace std;
const int N=1e4+5,M=1e5+5;
int n,m;
int idx,h[N],e[M],ne[M];
int times=0;
int dfn[N],low[N];
int bcc_cnt=0;
stack<int> S;
int ans1,ans2;
bool vis[N];
void c_plus(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void init(){
    idx=0;
    memset(h,-1,sizeof(h));
}
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void tarjan(int u,int fa){
    dfn[u]=low[u]=++times;
    S.push(u);
    for (int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if (dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]){
                ans1++;
            }
        }else if (dfn[v]<dfn[u] && v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u]){
        ++bcc_cnt;
        set<int> point;
        int sum=0;
        while (true){
            int x=S.top();
            point.insert(x);
            S.pop();
            if (x==u){
                break;
            }
        }
        for (auto x: point){
            for (int i=h[x];~i;i=ne[i]){
                int j=e[i];
                if (j!=i && point.count(j)){
                    sum++;
                }
            }
        }
        sum>>=1;
        if (sum>point.size()){
            ans2+=sum;
        }
    }
}
int main(){
    c_plus();
    init();
    cin>>n>>m;
    _for(i,0,m){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    _for(i,0,n){
        if (!vis[i]){
            tarjan(i,-1);
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
