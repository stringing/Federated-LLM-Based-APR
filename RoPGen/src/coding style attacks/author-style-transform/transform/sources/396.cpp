#include <iostream>
using namespace std;

int main() {
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    int n,m,arr[55][55];
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
    int ans = -2500000;
    for(int x1 = 0;x1 < n;x1++) {
        for(int y1 = 0;y1 < m;y1++) {
            for(int x2 = x1;x2 < n;x2++) {
                for(int y2 = y1;y2 < m;y2++) {
                    int sum = 0;
                    for(int i = 0;i < n;i++) {
                        for(int j = 0;j < n;j++) {
                            sum += arr[i][j];
                            if(sum > ans) {
                                ans = sum;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
