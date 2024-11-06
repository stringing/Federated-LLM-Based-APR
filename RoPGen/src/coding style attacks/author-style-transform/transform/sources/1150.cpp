#include <bits/stdc++.h>
using namespace std;
int n,m,a[100][100],h,maxs=0;
int main(){
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            for(int k=1; k<=m; k++){
                for(int r=k; r<=m; r++){
                    h = 0;
                    for(int c=i; c<=j; c++){
                        for(int d=k; d<=r; d++){
                            h = h + a[c][d];
                        }
                    }
                    maxs = max(maxs,h);
                }
            }
        }
    }
    cout << maxs;
    return 0;
}
