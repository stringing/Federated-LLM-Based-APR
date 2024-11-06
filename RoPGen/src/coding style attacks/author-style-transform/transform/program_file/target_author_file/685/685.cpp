#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200];
int sum(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}
bool cmp(int a,int b){
    if(sum[a] != sum[b]){
        return sum[a] < sum[b];
    }else{
        return a < b;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n,cmp);
    for(int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
