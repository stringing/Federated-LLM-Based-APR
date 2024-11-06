#include<bits/stdc++.h>
using namespace std;
int postOrder[35],inOrder[35],l[1010],r[1010],n;
int dfs(int x,int y,int len)
{
    int rl,p;
    if(len==0)
        return 0;
    for(int i=0;i<n;i++)
    {
        if(inOrder[i]==postOrder[x])
        {
            rl=y-i;
            p=i;
            break;
        }
    }
    r[postOrder[x]]=dfs(x-1,y,rl);
    l[postOrder[x]]=dfs(x-1-rl,p-1,len-rl-1);
    return postOrder[x];
}
int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>postOrder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inOrder[i];
    }
    int nq=dfs(n,n,n);
    for(int i=0;i<n;i++)
    {
        cout<<l[postOrder[i]]<<" "<<r[postOrder[i]]<<endl;
    }
}
