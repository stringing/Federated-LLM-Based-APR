#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    int s=0,u=0,a=x,b=y;
    while(a>0){
        s++;
        a/=10;
    }while(b>0){
        u++;
        b/=10;
    }if(s!=u) return s<u;
    else return x<y;
}
int main(){
    int n;
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a,a+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
} 
