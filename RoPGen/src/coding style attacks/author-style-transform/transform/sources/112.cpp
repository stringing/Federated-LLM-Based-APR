#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
bool cmp(int x ,int y){
    int sum1,sum2,m=x,n=y;
    while (x!=0){
        sum1+=x%10;
        x/=10;
    }
    while (y!=0){
        sum2+=y%10;
        y/=10;
    }
    if(sum1!=sum2){
        return sum1<sum2;
    }else{
        return m<n;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
