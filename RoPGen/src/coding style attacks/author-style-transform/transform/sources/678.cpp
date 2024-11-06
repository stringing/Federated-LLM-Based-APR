#include<bits/stdc++.h>
using namespace std;

int n,a[100005],ans=0;
map<int,int> m;

int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i] == 0) a[i] = -1;
        a[i] = a[i] + a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(!m.count(a[i])){
            m[a[i]] = i;
        }
    }
    for(int i=1;i<=n;i++){
        if(m.count(a[i])){
            ans = max(ans,abs(i - m[a[i]]));
        }
    }
    cout << ans << endl;
    
    return 0;
}
