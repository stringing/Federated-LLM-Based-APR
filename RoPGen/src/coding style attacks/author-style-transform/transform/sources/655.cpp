#include <bits/stdc++.h>
using namespace std;
const int maxn=1234;
vector<int> G[maxn];
int fa[maxn];
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            fa[v]=u;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int v:G[i]){
                if(G[i].size()<G[v].size()){
                    flag=false;
                    break;
                }
            }
            if(flag&G[i].size()>=G[fa[i]].size()){
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
