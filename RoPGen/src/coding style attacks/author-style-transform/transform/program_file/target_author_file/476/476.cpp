#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001];
int R[10001],L[10001];
int vis[10001];
int n;
int so(int x,int y,int len)
{
    if(len==0)
    {
        return 0;
    }else if(len==1){
        return a[x];
    }
    int p=y;
    while(a[x]!=b[p])
    {
        p--;
    }
    int k=y-p;
    R[a[x]]=so(x-1,y,k);
    L[a[x]]=so(x-k-1,p-1,len-k-1);
    return a[x];
}
int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    so(n,n,n);
    for(int i=1;i<=n;i++)
    {
        cout<<L[i]<<" "<<R[i]<<endl;
    }
    return 0;
}
