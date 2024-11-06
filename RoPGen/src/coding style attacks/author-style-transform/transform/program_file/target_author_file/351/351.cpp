#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n,m;
    int max=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=j;k++){
                for(int q=j;q<=m;q++){
                    int sum=0;
                    for()
                }
            }
        }
    }
   
    
    return 0;
}

