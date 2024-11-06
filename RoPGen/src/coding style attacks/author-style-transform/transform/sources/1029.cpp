#include <bits/stdc++.h>
using namespace std;
int m[35],b[35];
int treel[1005],treer[1005];
int tree[1005];
int n;
int dfs(int lm,int rm,int lb,int rb){
    if(lm>rm) return 0;
    int rt=b[rb];
    int p=tree[rt];
    int len_l=p-lm,len_r=rm-p;
    treel[rt]=dfs(lm,p-1,lb,lb+len_l-1);
    treer[rt]=dfs(p+1,rb,rb-len_r,rb-1);
    return rt;
} 
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        cin >> m[i];
    }
    for(int i=1;i<=n;i++){
        tree[m[i]]=i;
    }
    dfs(1,n,1,n);
    for(int i=1;i<=1000;i++){
        if(tree[i]) cout << treel[i] << ' ' << treer[i] << endl;
    }
    return 0;
} 
