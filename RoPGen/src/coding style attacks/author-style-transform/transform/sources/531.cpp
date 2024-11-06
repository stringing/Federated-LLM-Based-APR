#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
int sum[100005];
vector<int> v[20005];
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a);
        if(a== 0){
            sum[i] = sum[i - 1] + 1;
        }else{
            sum[i] = sum[i - 1] - 1;
        }
        v[sum[i] + 100001].push_back(i);
        if(sum[i] == 0){
            ans = i;
        }
    }
    for(int i = 0 ;i < 200005;i++){
        if(v[i].size() > 1){
            ans = max(ans,v[i][v[i].size() - 1] - v[i][0]);
        }
    }
    cout << ans << endl;
    return 0;
}
