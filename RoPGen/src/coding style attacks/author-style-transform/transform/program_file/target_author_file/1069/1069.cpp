#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[15],b[15],ans=1e9;
void dfs(int t,int temp,int sum){
    if(t==n){
        ans=min(ans,abs(temp-sum));
        return;
    }
    dfs(t+1,temp*a[t+1],sum+b[t+1]);
    dfs(t+1,temp,sum);
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    dfs(0,1,0);
    cout<<ans;
}
