#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    int cnt[100000]={0};
    int a[100000];
    int n,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) a[i]--;
        cnt[i]=cnt[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            l=i;
            break;
        }   
    }for(int i=n;i>=1;i--){
        if(cnt[i]==0){
            r=i;
            break;
        }
    }
    cout<<r-l;
    return 0;
}
