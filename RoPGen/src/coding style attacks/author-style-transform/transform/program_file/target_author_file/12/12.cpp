#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        vector<int> G[1005];
        int n;
        cin>>n;
        for (int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int cnt=0;
        for (int i=1;i<=n;i++){
            bool ad=true;
            for (int j=0;j<G[i].size();j++){
                if (G[G[i][j]].size()>G[i].size()){
                    ad=false;
                    break;
                }
            }
            if (ad){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
