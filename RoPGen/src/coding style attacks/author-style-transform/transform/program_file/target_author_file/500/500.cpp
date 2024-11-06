#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],minn=INT_MAX;
int f(int u,int sum){
    if(sum==m){
        return 0;
    }
    if(sum>m&&sum-m<minn){
        minn=sum-m;
    }
    if(u==n){
        return minn;
    }
    f(u+1,sum+a[u]);
    f(u+1,sum);
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<f(0,0);
    return 0;
}
