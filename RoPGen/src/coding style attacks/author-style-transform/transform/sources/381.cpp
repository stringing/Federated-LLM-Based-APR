#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int R[100];
int L[100];
int z[100];
int h[100];
int solve(int x,int y,int len){
    if(len==0) return 0;
    int p=y;
    while(h[x]!=z[x]){
        p--;        
    }
    int k=y-p;
    R[h[x]]=solve(x-1,y,k);
    L[h[x]]=solve(x-k-1,p-1,len-k-1);
    return h[x];
}
int n;
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>z[i];
    solve (1,1,n);
    for(int i=1;i<=n;i++)cout<<R[i]<<' '<<L[i]<<endl;
    return 0;
}

