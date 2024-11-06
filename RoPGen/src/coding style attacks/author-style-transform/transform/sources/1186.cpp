#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n,m,a[60][60],ans;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    ans=a[0][0];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            for(int o=i;o<n;++o)
                for(int p=j;p<n;++p){
                    int tot=0;
            for(int x=i;x<=o;++x)
                for(int y=j;y<=p;++y){
                    tot+=a[x][y];
                }
            if(tot>ans)
                ans=tot;
                                    }
        }
    cout<<ans;
    return 0;
}
