#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
const int MAX = 105;
struct Node {
    int val,l,r;
} node[MAX];
int tot;
int c[MAX],b[MAX]; 
int dfs(int len,int b[],int c[]) {
    if(len <= 0) return -1;
    if(len == 1) {
        node[++tot].val = b[1];
        node[tot].l=node[tot].r = -1;
        return tot;
    }
    node[++tot].val = c[len];
    int res = tot;
    int l;
    for(l = 1; l<=len; l++) {
        if(b[l] == c[len]) break;
    }
    node[res].l = dfs(l-1,b,c);
    
    node[res].r = dfs(len-l,b+l,c+l-1);
    return res;
} 
void bfs() {
    queue<int> q;
    q.push(1);
    while(q.size()) {
        int cur = q.front();q.pop();
        if(cur != 1) printf(" ");
        printf("%d",node[cur].val);
        if(node[cur].l != -1) q.push(node[cur].l);
        if(node[cur].r != -1) q.push(node[cur].r);
    }
    printf("\n");
}
int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) scanf("%d",c+i);
    for(int i = 1; i<=n; i++) scanf("%d",b+i);
    dfs(n,b,c);
    bfs();
    
    bfs();
    return 0 ;
}
