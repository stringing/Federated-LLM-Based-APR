#include<iostream>
#include<algorithm>
using namespace std;
int a1,a2;
bool cmp(int a,int b){
    int ans[500]={0,0};
    while(a!=0){
        ans[1]+= a%10;
        a/=10;
    }
    while(b!=0){
        ans[2]+=b%10;
        b/=10;
    }
    if(ans[1]!=ans[2]){
        return ans[1]>ans[2];
    }
    return a<b;
    }


int main(){
    int n;
    int a[110];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    
}
