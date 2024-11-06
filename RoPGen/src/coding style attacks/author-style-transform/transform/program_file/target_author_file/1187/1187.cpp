#include<bits/stdc++.h>
using namespace std;
vector<int> G[1005];
int ans=0;
bool f;
int fa[1005];
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t,n,x,y;
    cin>>t;
    while(t--){
            cin>>n;
            for(int i=0;i<n-1;i++){
                cin>>x>>y;
                G[x].push_back(y);
                fa[y]=x;
            }
            for(int i=1;i<=n;i++){
                f=true;
                for(int j=0;j<G[i].size();j++){
                    if(G[i].size()<G[G[i][j]].size()){
                        f=false;
                        break;
                    }
                }
                if(f && G[i].size()>=G[fa[i]].size())
                    {
                        ans++;
                    }
            }
            cout<<ans<<endl;
            for(int i=1;i<=n;i++){
                vector<int>().swap(G[i]);
            }
            memset(fa,0,sizeof(fa));
        }
    return 0;
}
