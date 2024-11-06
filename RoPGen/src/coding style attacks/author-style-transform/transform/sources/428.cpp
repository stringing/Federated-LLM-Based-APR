#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> a[105];
int fa[1005];
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n-1; i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            fa[y]=x;
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            bool f=true;
            for(int j=0; j<a[i].size(); j++){
                if(a[i].size() <= a[a[i][j]].size()){
                    f=false;
                    break;
                }
            }
            if(f && a[i].size()>=a[fa[i]].size()){
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1; i<=n; i++){
            vector<int>().swap(a[i]);
        }
        memset(fa,0,sizeof(fa));
    }
    return 0;
}
