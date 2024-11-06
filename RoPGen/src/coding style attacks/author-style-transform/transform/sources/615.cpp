#include <iostream>
using namespace std;
int main() {
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    int n,m,a[51][51];
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int x = 0;
    for(int i = 1; i <= n; i++) {
        x += a[i][m];
    }
    for(int i = 1; i <= m; i++) {
        x += a[n][i];
    }
    cout << x - a[n][m];
    return 0;
}
