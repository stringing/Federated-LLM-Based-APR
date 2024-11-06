#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],b[1000001],minn=1e9;
void dfs(int x,int sum1,int sum2) {
    if(x==n){
        minn=min(abs(sum1-sum2),minn);
        return ;
    }
    dfs(x+1,sum1*a[x],sum2+b[x]);
    dfs(x+1,sum1,sum2);
}
int main() {
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    dfs(0,1,0);
    cout<<minn;
    return 0;
}
