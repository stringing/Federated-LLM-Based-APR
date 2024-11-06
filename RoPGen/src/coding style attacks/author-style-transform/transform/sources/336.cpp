#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        vector<int> v[1005];
        vector<int> w[1005];
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            w[y].push_back(x);
        }for(int i=1;i<=n;i++){
            int temp=0;
            for(int j=0;j<v[i].size();j++){
                temp+=v[j].size();
            } for(int j=0;j<w[i].size();j++){
                temp+=v[w[i][j]].size();
            }if(v[i].size()>=temp){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
