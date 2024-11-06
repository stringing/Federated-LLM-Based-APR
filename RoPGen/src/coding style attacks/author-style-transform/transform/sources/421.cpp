#include <iostream>
#include <algorithm>
using namespace std;
int a[105];

bool cmp(int x,int y){
    if(x%2!=y%2){
        return x%2>y%2;
    }else{
        return x<y;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a,a+n,cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
