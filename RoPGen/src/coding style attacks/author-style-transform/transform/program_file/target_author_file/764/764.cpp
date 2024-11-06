#include <iostream>
using namespace std;
int ans,n,vis[10][10];
bool row1[10],x1[20],y1[20];
bool row2[10],x2[20],y2[20];
bool check(int c,int i,int f) {
    if (f==2) {
        return !row1[i] && !x1[c+i] && !y1[c-i+8] && vis[c][i]==1;
    } else {
        return !row2[i] && !x2[c+i] && !y2[c-i+8] && vis[c][i]==1;
    }
}
void dfs(int c) {
    if (c==n) {
        ans++;
        return;
    }
    for (int i=0;i<n;i++) {
        if (check(c,i,2)) {
            vis[c][i]=2;
            row1[i]=x1[c+i]=y1[c-i+n]=true;
            for (int j=0;j<n;j++) {
                if (check(c,i,3)) {
                    vis[c][j]=3;
                    row2[i]=x2[c+i]=y2[c-i+n]=true;
                    dfs(c+1);
                    row2[i]=x2[c+i]=y2[c-i+n]=false;
                    vis[c][j]=1;
                }
            }
            vis[c][i]=1;
            row1[i]=x1[c+i]=y1[c-i+n]=false;
        }
    }
}
int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> vis[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;    
}
