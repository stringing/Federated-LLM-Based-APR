#include<iostream>
using namespace std;
int a[50][50];
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int ans = 0,flag = 0;
  for(int i1 = 0; i1 < n; i1++) {
    for(int j1 = 0; j1 < m; j1++) { 
      for(int i2 = i1; i2 < n; i2++) { 
        for(int j2 = j1; j2 < m; j2++) {
          int sum = 0;
             for(int i3 = i1; i3 <= i2; i3++) {
                for(int j3 = j1; j3 <= j2; j3++) {
                  if(flag < n * n) {
                    cin >> a[j3][i3];
                    flag++;
                  }                 
                  
                sum += a[i3][j3];
           }
         }
         ans = max(sum,ans);
       }
     }
    }
  }
  cout << ans;
    return 0;
}
