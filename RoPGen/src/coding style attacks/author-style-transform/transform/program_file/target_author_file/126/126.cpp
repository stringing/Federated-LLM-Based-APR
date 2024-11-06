#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int x,y,z,n;
    cin>>n;
    int a,b,c,d;
    for(x=0;x*x<n;x++){
        for(y=x;y*y<n;y++){
            for(z=y;z*z<=n;z++){
                if(x*x+x*y+z*z+sqrt(n-x*x-y*y-z*z)*sqrt(n-x*x-y*y-z*z)==n){
                    cout<<x<<" "<<y<<" "<<z<<" "<<sqrt(n-x*x-y*y-z*z);
                    return 0;
                }
            }
        }
    }
}
