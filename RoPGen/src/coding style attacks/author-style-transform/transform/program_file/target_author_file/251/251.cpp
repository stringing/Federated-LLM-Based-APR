#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    int n,a[100000],i0=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-1]*9+n*3+n*2<<endl;
    return 0;
}
