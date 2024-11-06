#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long time=0,luo=0;
    long long n,a[10000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=luo){
            time+=(a[i]-luo)*5+5;
        }else{
            time+=(luo-a[i])*4+5;
        }
        luo=a[i];
    }
    time+=luo*4;
    cout<<time;
    return 0;
}
