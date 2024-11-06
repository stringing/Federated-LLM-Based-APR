#include <iostream>
#include <algorithm>
using namespace std;
int n,a[102];
int sum(int x){
    int s = 0;
    while(x){
        s+=x%10;
        x/=10;
}
    return s;
}
bool cmp(int x,int y){
        return sum(x)<sum(y);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
}
    sort(x,x+n,cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
