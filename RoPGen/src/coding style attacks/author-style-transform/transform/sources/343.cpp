#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int m,n,a[10110],b[100010]; 
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(binary_search(a,a+m,b[i])){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
return 0;
}

