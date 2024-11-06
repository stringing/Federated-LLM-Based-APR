#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int Middle[35]={0},End[35]={0},n=0,Left[35]={0},Right[35]={0},root=0,num[35]={0};
void dfs(int l1,int r1,int l2,int r2)
{
    if(l1==r1)
    {
        return;
    }
    int g;
    for(int i=l2;i<=r2;i++)
    {
        if(End[i]==Middle[r1])
        {
            g=i;
            break;
        }
    }
    if(g==l2){
        Right[Middle[r1]]=Middle[r1-1];
        dfs(l1,r1 - 1,l2+1,r2);
    } else if(g==r2){
        Left[Middle[r1]]=Middle[r1-1];
        dfs(l1,r1-1,l2,r2-1);
    } else {
        Left[Middle[r1]]=Middle[g-l2+l1-1];
        Right[Middle[r1]]=Middle[r1-1];
        dfs(l1,g-l2+l1-1,l2,g-1);
        dfs(g-l2+l1,r1-1,g+1,r2);
    }
    return;
}
int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>Middle[i];
        num[i]=Middle[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>End[i];
    }
    sort(num+1,num+n+1);
    root=Middle[n];
    dfs(1,n,1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<Left[num[i]]<<' '<<Right[num[i]]<<endl;
    }
    return 0;
}
