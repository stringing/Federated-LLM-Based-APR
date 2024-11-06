#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("pair.in", "r", stdin);
    freopen("pair.out", "w", stdout);
    int n;
    cin>>n;
    int a[1000001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            a[i]=-1;
        }
    }
    int sum[1000001]={};
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            if(sum[j]-sum[i]==0){
                if(cnt<j-i){
                    cnt=j-i;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}

