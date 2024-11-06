#include <bits/stdc++.h>
using namespace std; 
int main(){
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int num[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> num[i][j];
        }
    }
    int max = -10000;
    for(int y1 = 0; y1 < m; y1++){
        for(int y2 = y1; y2 < m; y2++){
            for(int x1 = 0; x1 < n; x1++){
                for(int x2 = x1; x2 < n; x2++){
                    int sum = 0;
                    for(int a = x1; a < x2; a++){
                        for(int b = y1; b < y2; b++){
                            sum += num[b][a];
                        }
                        if(sum > max){
                            max = sum;
                        }
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}
