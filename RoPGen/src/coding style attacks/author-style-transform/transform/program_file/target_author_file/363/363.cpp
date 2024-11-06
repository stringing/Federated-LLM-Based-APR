#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001];
int len,len2;
int main(){
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            len=1;
            for(int k=0;k<1000001;k++){
                a[k]=0;
            }
            a[0]=1;
            for(int k=0;k<len;k++){
                a[k]*=j;
            }
            for(int k=0;k<len;k++){
                a[k+1]+=a[k]/10;
                a[k]/=10;
            }
            while(a[len]){
                a[len+1]+=a[len]/10;
                a[len]%=10;
                len++;
            }
        }
        len2=len;
        for(int j=0;j<len2;j++){
            b[j]+=a[j];
        }
        for(int j=0;j<len2;j++){
            b[j+1]+=b[j]/10;
            b[j]%=10;
        }
        while(b[len2]){
            b[len2+1]+=b[len2]/10;
            b[len2]%=10;
            len2++;
        }
    }
    cout<<len2<<endl;
    for(int i=len2-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}

