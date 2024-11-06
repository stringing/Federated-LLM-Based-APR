#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,indexx,oldv[10010],v[10010],ans;
char maze[110][110];
vector<int>oldg[10010],g[10010];
int teleport[10010];
int id(int x,int y){
    return (x - 1) * m + y;
}
bool in(int x,int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dfn[10010],low[10010],times,scc[10010],scc_cnt;
stack<int>s;
void tarjan(int u){
    dfn[u] = low[u] = ++times;
    s.push(u);
    for(int i = 0 ;i < oldg[u].size();i ++){
        int v = oldg[u][i];
        if(dfn[v] == 0){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(scc[v] == 0){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        scc_cnt++;
        while(true){
            int tmp = s.top();
            s.pop();
            scc[tmp] = scc_cnt;
            v[scc_cnt] += oldv[tmp];
            if(tmp == u){
                break;
            }
        }
    }
    return;
}
int dp[10010];
int dfs(int u){
    if(dp[u] != 0){
        return dp[u];
    }
    dp[u] = v[u];
    for(int i = 0 ;i < g[u].size();i ++){
        int vv = g[u][i];
        dp[u] = max(dp[u],dp[vv] + v[u]);
    }
    return dp[u];
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> maze[i][j];
            if(maze[i][j] == '*')cnt ++;
        }
    }
    for(int i = 1;i <= cnt;i ++){
        int x,y;
        cin >> x >> y;
        if(maze[x + 1][y + 1] != '#')teleport[i] = id(x + 1,y + 1);
        else teleport[i] = -1;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(maze[i][j] != '#'){
                if(maze[i][j] != '*')oldv[id(i,j)] = maze[i][j] - '0';
                if(in(i + 1,j)){
                    if(maze[i + 1][j] != '#'){
                        oldg[id(i,j)].push_back(id(i + 1,j));
                    }
                }
                if(in(i,j + 1)){
                    if(maze[i][j + 1] != '#'){
                        oldg[id(i,j)].push_back(id(i,j + 1));
                    }                    
                }
            }
            if(maze[i][j] == '*'){
                indexx ++;
        if(teleport[indexx] != -1)oldg[id(i,j)].push_back(teleport[indexx]);
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(dfn[id(i,j)] == 0 && maze[i][j] != '#'){
                   tarjan(id(i,j));
            }
        }
    }
    for(int i = 1;i <= n;i ++){
            for(int y = 1;y <= m;y ++){
                for(int j = 0;j < oldg[id(i,y)].size();j ++){
                    int v = oldg[id(i,y)][j];
                    if(scc[id(i,y)] != scc[v]){
                        g[scc[id(i,y)]].push_back(scc[v]);
                    }
            }
        }
    }
    
    for(int i = 1;i <= scc_cnt;i ++){
        ans = max(ans,dfs(i));
    }
    cout << ans << endl;
    return 0;
}
