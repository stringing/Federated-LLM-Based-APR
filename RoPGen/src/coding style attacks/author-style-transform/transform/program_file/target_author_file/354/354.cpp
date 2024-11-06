#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
    int sum=0,num=0;
    while(x<=0){
        sum+=x%10;
        x/=10;
    }
    while(y<=0){ 
        num+=y%10;
        y/=10;
    }
    if(sum == num){
        return x < y;
    }
}
int main(){
    int a[1001];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
} 

