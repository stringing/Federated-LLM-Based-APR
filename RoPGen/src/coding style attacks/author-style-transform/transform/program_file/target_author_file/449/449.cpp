#include <iostream>
using namespace std;
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n, m, a[51][51], max = -2500001;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            for(int k = 0; k < m; k++) {
                for(int l = 1; l <= m - k; l++) {
                    int sum = 0;
                    for(int p = i; p < j; p++) {
                        for(int q = k; k < l; q++) {
                            sum += a[p][q];
                        }
                    }
                    if(sum > max) {
                        max = sum;
                    }
                }
            }
        }
    }
    cout << max;
    return 0;
}
