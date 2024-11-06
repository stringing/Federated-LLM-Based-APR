#include<bits/stdc++.h>
using namespace std;
int vis[1000005];
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    int n,sum=100000;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1){
            sum++;
        }
        else {
            sum--;
        }
        if(sum==100000){
            sum=i;
        }else if(vis[sum]==0){
            vis[sum]=i;
        }else{
            sum=max(sum,i-vis[sum]);
        }
    }
   cout<<sum<<endl;
    return 0;
}
