#include <iostream>
#include <cstdio>
using namespace std;
int ans[40005],len,lensum;
int main() {
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    int n;
    cin >> n;
    len=1;
    lenans=1;
    while(n--){
        int a[40005];
        a[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<len; j++){
                a[j]*=i;        
            }
            for(int j=0; j<len; j++){
                a[j+1]+=a[j]/10;           
                a[j]%=10;       
            }     
            while(a[len]){           
                a[len+1]+=a[len]/10;
                a[len]%=10;
                len++;
            }
            lenans=max(len,lenans);        
            for(int i=0; i<lensum; i++){
                ans[i]+=a[i];
            }
            while(ans[lenans]){
                ans[lenans+1]+=ans[lenans]/10;
                ans[lenans]%=10;
                lensum++;
            }
        }
    }
    for(int i=lenans-1; i>=0; i--){
        cout<<ans[i];
    }
    return 0;
}
