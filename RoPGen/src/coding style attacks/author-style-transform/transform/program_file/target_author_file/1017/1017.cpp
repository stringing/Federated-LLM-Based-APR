#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],a1[1005];
int main() {
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int n, t;
    cin >> t;
   while(t--){
       cin>>n;
       int x,y;
       memset(a,0,sizeof(a));
       memset(a1,0,sizeof(a1));
       int ans=n;
       for(int i=1;i<n;i++){
            
            cin>>x>>y;
            a1[x]++;
            a[x][y]=a[y][x]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]&&a1[i]<a1[j]){
                    ans--;
                    break;
                }
            }
        }
        cout<<ans;
    }
    
    
    return 0;
}
