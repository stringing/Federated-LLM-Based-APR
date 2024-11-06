#include<bits/stdc++.h>
using namespace std;
int zfc[10005];
bool uui(int x,int y){
    int x1=0,y1=0;
    while(x){
        x1+=x%10;
        x/=10;
    }
    while(y){
        y1+=y%10;
        y/=10;
    }
    if(x1==y1){
        return 1;
    }
    return x1<y1;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>zfc[i];
    }
    sort(zfc,zfc+n,uui);
    for(int i=0;i<n;i++){
        cout<<zfc[i]<<" ";
    }
    return 0;
}
