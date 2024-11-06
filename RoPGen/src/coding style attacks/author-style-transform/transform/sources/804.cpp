#include<bits/stdc++.h>
using namespace std;
int main(){
    double n,a,b;
    int ans;
    cin>>n>>a>>b;
    ans=(n*a-600)/(max(a,b)-min(a,b));
    cout<<ans;
    return 0;
}
