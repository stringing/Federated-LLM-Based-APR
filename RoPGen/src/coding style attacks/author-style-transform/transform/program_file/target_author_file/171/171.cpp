#include <bits/stdc++.h> 
using namespace std; 
int N;
int a[35];
int b[35];
int s[35];
int tree[1010], pos[1010];
void dfs(int &root, int x) {
    if(tree[root] == 0){
        tree[root] = x;
        return;
    } if (x < tree[root]){
        root *= 2;
        dfs(root,x);
    } else if(x > tree[root]){
        root *= 2;
        root++;
        dfs(root,x);
    }
}
int main() { 
    freopen("sort.in","r",stdin); 
    freopen("sort.out","w",stdout);
    
    int n;
    cin >> n;
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[i] = 1;
        dfs(pos[i], x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cout  << tree[pos[i] * 2] << ' ' << tree[pos[i] * 2 + 1] << endl;
    }
    return 0; 
}

