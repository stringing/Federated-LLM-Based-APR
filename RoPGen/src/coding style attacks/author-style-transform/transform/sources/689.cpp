#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char c[110][110];
int cs_num,cs_pos[10010],cs_target[10010];
struct note
{
    int iscs=0;
    int value=1;
};
note drop[10010];
struct bian
{
    int v,nxt;
};
int head[10010],num;
bian g[100010];
int dfn[10010],low[10010];
int times=0;
int dropnum;
int scc_cnt;
int sccno[10010];
vector<int> scc[10010];
stack<int> S;
bian gx[100010];
int headx[10010],numx;
int indegree[10010];
int vis[10010];
int sccvalue[10010];
int ans;
int fp[110][110];
int start_scc;
void init()
{
    for(int i=0;i<=n*n;i++) head[i]=-1;
}
void dfs(int u)
{
    dfn[u]=low[u]=++times;
    S.push(u);
    for(int i=head[u];i!=-1;i=g[i].nxt)
    {
        int v=g[i].v;
        if(dfn[v]==0)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        } else if(!sccno[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        scc_cnt++;
        while(!S.empty())
        {
            int x=S.top();
            S.pop();
            scc[scc_cnt].push_back(x);
            sccno[x]=scc_cnt;
            if(drop[x].iscs==0) sccvalue[scc_cnt]+=drop[x].value;
            if(x==u) break;
        }
    }
}
void dfsx(int u,int money)
{
    if(money<=vis[u]) return;
    vis[u]=money;
    ans=max(ans,money);
    for(int i=head[u];i!=-1;i=g[i].nxt)
    {
        int v=g[i].v;
        
        dfsx(v,money+sccvalue[v]);
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]>='1'&&c[i][j]<='9')
            {
                dropnum++;
                drop[dropnum].iscs=0;
                drop[dropnum].value=c[i][j]-'0';
                fp[i][j]=dropnum;
            }
            else if(c[i][j]=='*')
            {
                dropnum++;
                drop[dropnum].iscs=1;
                fp[i][j]=dropnum;
                cs_num++;
                cs_pos[cs_num]=fp[i][j];
            }
        }
    }
    for(int i=1;i<=cs_num;i++)
    {
        cin>>a>>b;
        cs_target[i]=fp[a+1][b+1];
    }
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(c[i][j]!='#'&&c[i][j+1]!='#')
            {
                num++;
                g[num].v=fp[i][j+1];
                g[num].nxt=head[fp[i][j]];
                head[fp[i][j]]=num;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]!='#'&&c[i+1][j]!='#')
            {
                num++;
                g[num].v=fp[i+1][j];
                g[num].nxt=head[fp[i][j]];
                head[fp[i][j]]=num;
            }
        }
    }
    for(int i=1;i<=cs_num;i++)
    {
        if(cs_target[i]!=0)
        {
            num++;
            g[num].v=cs_target[i];
            g[num].nxt=head[cs_pos[i]];
            head[cs_pos[i]]=num;
        }
    }
    dfs(fp[1][1]);
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j!=-1;j=g[j].nxt)
        {
            
            if(sccno[i]!=sccno[j])
            {
                int v=g[j].v;
                
                numx++;
                gx[numx].v=sccno[v];
                gx[numx].nxt=headx[sccno[i]];
                headx[sccno[i]]=numx;
                indegree[sccno[v]]++;
            }
        }
    }
    start_scc=sccno[fp[1][1]];
    dfsx(start_scc,sccvalue[start_scc]);
    cout<<ans;
    return 0;
}
