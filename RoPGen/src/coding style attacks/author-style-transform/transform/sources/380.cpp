#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int Left[1100],Right[1100];
int z[1000],h[1000];
void dfs(int l1,int r1,int l2,int r2){
    int pos;
    if(l1==r1){
        return ;
    }
    for(int i=l2;i<=r2;i++){
        if(z[i]==h[r1]){
            pos=i;
            break;
        }
    }
    if(pos==l2){
        Right[h[r1]]=h[r1-1];
        dfs(l1,r1-1,l2+1,r2);
    }else if(pos==r2){
        Left[h[r1]]=h[r1-1];
        dfs(l1,r1-1,l2,r2-1);
    }else{
        Left[h[r1]]=h[pos-l2+l1-1];
        Right[h[r1]]=h[r1-1]; 
        dfs(l1, pos - l2 +l1-1,l2,pos -1);
        dfs(pos-l2+l1,r1-1,pos+1,l2);
    }
}
int n;
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>z[i];
    dfs(1,n,1,n);
    for(int i=1;i<=n;i++){
        cout<<Left[i]<<' ';
        cout<<Right[i]<<endl;
    }
    return 0;
}

