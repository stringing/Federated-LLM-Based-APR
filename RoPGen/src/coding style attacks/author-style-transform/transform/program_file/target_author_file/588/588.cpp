#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int a[100][100];
    int n,m;
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int o;
            cin>>o;
            a[i][j]=o;
           
        }
    }
    int sum=0,max=1001;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int l=1;l<=m;l++){
                for(int k=l;k<=m;k++){
                    sum=a[i]+a[j]+a[l]+a[k];
                    if(max<sum){
                        max=sum;
                    }
                }
            }
        }
    }
    return 0;
}
