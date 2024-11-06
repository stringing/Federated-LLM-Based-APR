#include<iostream>
using namespace std;
bool a[100000005];
void find(int x){
    if(a[x] == 1){
        cout << x;
        return;
    }
    a[x] = 1;
    cout << x <<",";
    if(x % 2 == 0){
        find(x / 2);
    }else{
        find((x - 1) * 3 + 6);
    }
}
int main(){
    int n;
    cin >> n;
    find(n);
}
