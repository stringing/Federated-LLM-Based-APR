#include<bits/stdc++.h>
using namespace std;
int mp[10][10];
int vy[10],vd1[20],vd2[20];
int n,ans;
void dfs(int x,int p){
        if(x==n&&p==2){
                ans++;
                return ;
        }
        if(x==n){
                dfs(0,p+1);
                return ;
        }
        for(int i=0;i<n;i++){
                if(mp[x][i]&&vy[i]!=3&&vy[i]!=p&&vd1[x+i]!=3&&vd1[x+i]!=p&&vd2[x-i+n]!=3&&vd2[x-i+n]!=p){
                        mp[x][i]=0;
                        vy[i]+=p;
                        vd1[x+i]+=p;
                        vd2[x-i+n]+=p;
                        dfs(x+1,p);
                        vy[i]-=p;
                        vd1[x+i]-=n;
                        vd2[x+n-i]-=p;
                        mp[x][i]=1;
                }
        }
}
int main()
{
        freopen("queen.in","r",stdin);
        freopen("queen.out","w",stdout);
        cin>>n;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cin>>mp[i][j];
                }
        }dfs(0,1);
        cout<<ans<<endl;
        return 0;
}
