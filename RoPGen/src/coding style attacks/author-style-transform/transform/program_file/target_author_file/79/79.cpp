#include <iostream>
#include <vector>
#include<cstdio>
using namespace std;
const int maxn = 1005;
vector<int> G[105][maxn];
int F[105][1005];
int main() {
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int n,m,ans=0,ii=0;
    cin>>n;
    while(n--){
        cin>>m;
        for(int i=0;i<m-1;i++){
            int x,y;
            cin>>x>>y;
            G[ii][x].push_back(y);
            F[ii][y]=x;
        }
        for(int i=0;i<m;i++){
            bool flag=true;
            if(i!=0&&G[ii][i].size()>=G[ii][F[ii][i]].size()){
                 for(int j=0;j<G[ii][i].size();j++){
                     if(G[ii][G[ii][i][j]].size()>G[ii][i].size()){
                         flag=false;
                     }
                 }
             }
            if(flag){
                ans++;
            }
        }
        ii++;
    }
    cout<<ans<<endl;
    return 0;
}
