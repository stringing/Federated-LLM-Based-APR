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
    int sum = 0,max = -1;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int k = 0;k < n;k++) {
                for(int l = 0;l< n;l++) {
                    for(int m = 0;m < n;m++) {
                        for(int o = 0;o < n;o++) {
                            sum += arr[i][j] + arr[k][l] + arr[m][o];
                            if(sum > max) {
                                max = sum;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << max;
    return 0;
}
