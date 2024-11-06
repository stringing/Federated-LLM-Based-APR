#include <bits/stdc++.h>
using namespace std;
long long a[40005],cnt[40005],len=1,len2=1;
int main(){
    freopen("factorial.in","r",stdin);
    freopen("factorial.out","w",stdout);
    int n;
    cin>>n;
    a[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            a[j]*=i;
        }
        for(int j=1;j<=len;j++){
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
        while(a[len+1]){
            a[len+2]+=a[len+1]/10;
            a[len+1]%=10;
            len++;
        }
        for(int j=1;j<=len;j++){
            cnt[j]+=a[j];
            cnt[j+1]+=cnt[j]/10;  
            cnt[j]%=10;
        }
        len2=max(len,len2);
        while(cnt[len2]+1){
            cnt[len+2]+=cnt[len+1]/10;
            cnt[len+1]%=10;
            len2++;
        }    
    }
    for (int i = len2; i >= 1; i--) {
        cout<<cnt[i];
    }
    return 0;
}
