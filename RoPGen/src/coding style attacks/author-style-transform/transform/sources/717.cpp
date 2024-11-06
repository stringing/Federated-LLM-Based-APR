#include<iostream>
using namespace std;
long long f[100001];
long long t,cnt;
int main(){
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    int n,i = 0;
    cin>>n;
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        f[a]++;
    }
    for(i=1;cnt < n;i++){
        cnt += f[i];
        if(f[i] != 0){
            t++;
        }
    }
    cout<<i * 9 + t * 3 + n * 2;
    return 0;
}
