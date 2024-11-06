#include<bits/stdc++.h>
using namespace std;
int sum[1000000+10],cnt=0;
void fly(int n){
    if(find(1,cnt,n))return ;
    if(n%2==0){
        printf(", %d",n/2);
        cnt++;
        sum[cnt]=n;
        fly(n/2);
    }else{
        printf(", %d",6*((n-1)/2)+6);
        cnt++;
        sum[cnt]=n;
        fly(6*((n-1)/2)+6);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<n;
    fly(n);
}
