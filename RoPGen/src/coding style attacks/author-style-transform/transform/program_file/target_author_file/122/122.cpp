#include <bits/stdc++.h>
using namespace std;
int Pow(int m){
    return sqrt(m);
}
int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i*i;j++){
            for(int k=0;k<=n-j*j;k++){
                if(!Pow(n-(i*i)-(j*j)-(k*k))){
                    int a[4];
                    a[0]=i,a[1]=j,a[2]=k,a[3]=Pow(n-(i*i)-(j*j)-(k*k));
                    sort(a,a+4);
                    cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
