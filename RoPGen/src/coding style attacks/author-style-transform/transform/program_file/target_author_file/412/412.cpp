#include<bits/stdc++.h>
using namespace std;
int n,b,a[100001],h,t,sum,a2[1000001],point;
int search() {
    h=1;
    t=2;
    while(h<n) {
        sum+=a[h];
        while(t!=n)
        {
            for(int i=t; i<=n; i++) {
            
            sum+=a[i];
            if(sum>=b) {
                point++;
                a2[point]=sum-b;
                break;
            }
        }
        t++;sum=a[h];
        }
        
        h++;t=h+1;
    }
    sort(a2+1,a2+point+1);
    return a2[1];
}
int main() {
    freopen ("shelf.in" , "r" , stdin);
    freopen ("shelf.out" , "w" , stdout);
    cin>>n>>b;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(a[i]==b) {
            cout<<0;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    cout<<search();
    return 0;
}
