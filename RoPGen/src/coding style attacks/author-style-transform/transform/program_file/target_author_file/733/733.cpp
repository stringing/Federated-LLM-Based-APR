#include <iostream>
using namespace std;

int main() {
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
                max = 0;
                for(int w = 0;w < n;w++) {
                    sum += arr[i][j];
                }
                if(sum > max) {
                    max = sum;
                }
            }
        }
    }
    cout << max;
    return 0;
}
