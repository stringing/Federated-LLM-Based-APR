#include<iostream>
#include<map>
using namespace std;
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    int n,l[100004],i,mx=0;
    map<int,int> cnt;
    cin>>n;
    l[0]=0;
    for(i=1;i<=n;i++){
        int k;
        cin>>k;
        if(!k) k=-1;
        l[i]=l[i-1]+k;
        if(cnt.count(l[i])) mx=max(i-cnt[l[i]],mx);
        else cnt[l[i]]=i;
    }
    cout<<mx;
}
