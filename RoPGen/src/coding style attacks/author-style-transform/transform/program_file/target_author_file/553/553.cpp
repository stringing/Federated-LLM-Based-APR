#include <bits/stdc++.h>
using namespace std;
vector <int> G[1001];
int fa[1001];
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>n;
            int x,y;
            cin>>x>>y;
            G[x].push_back(y);
            fa[y]=x;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int j=0;j<G[i].size();j++){
                if(G[i].size()<G[G[i][j]].size()){
                    flag=false;
                    break;
                }
            }
            if(flag&&G[i].size()<=G[fa[i]].size()){
                ans++;
            }
        }
        cout<<ans<<endl;
        memset(fa,0,sizeof(fa));
        for(int i=0;i<=n;i++){
            vector<int>().swap(G[i]);
        }
    }
    return 0;
}
