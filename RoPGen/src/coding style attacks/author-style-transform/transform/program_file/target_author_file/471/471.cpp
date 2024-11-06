#include<iostream>
using namespace std;
int a[1005][1005];
int main(){
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    int max = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int y = 0;y < m;y++){
                for(int u = y + 1;u < m;u++){
                    int sum = 0;
                    sum += a[i][y] + a[i][u] + a[j][y] + a[j][u];
                    if(sum > max){
                        max = sum;
                    }
                }
            }
        }
    }
    cout << max; 
    return 0;
}
