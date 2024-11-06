#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int x,y,z,n;
    cin>>n;
    int a,b,c,d;
    for(x=0;x*x<n;x++){
        for(y=x;x*x+y*y<n;y++){
            for(z=y;x*x+y*y+z*z<=n;z++){
                double tmp1=sqrt(n-x*x-y*y-z*z);
                int tmp2=n-x*x-y*y-z*z;
                if(tmp1*tmp1==tmp2&&tmp1>=z){
                    cout<<x<<" "<<y<<" "<<z<<" "<<sqrt(n-x*x-y*y-z*z);
                    return 0;
                }
                }
            }
        }
 }
