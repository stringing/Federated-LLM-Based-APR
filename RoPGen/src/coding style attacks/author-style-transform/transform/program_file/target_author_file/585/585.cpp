#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(int x,int y){return x < y;}
int main() {
    int n,m;
    cin>>n;
    int a[n]={},b[n]={};
    for(int i=0;i<n;i++){
        cin>>m;
        b[i]=m;
        for(int j=0;m;j++){
            a[i]+=m%10;
            m/=10;
        }
        
    }
    
    sort(a,a+n,cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}
