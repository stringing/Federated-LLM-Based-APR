#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[102];
int sum(int x){
    int s=0;
    while(x){
        s+=x%10;
        x/=10;
    }
    return s;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,sum);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
