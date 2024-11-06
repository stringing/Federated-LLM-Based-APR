#include<iostream>
using namespace std;
const int N = 70;
long long a[N] = {0,1,2,4};
void f(long long n){
    if(n == 12){
      cout <<"12, 6, 3, 12";
        return;
    }
    if(n == 6){
        cout <<"6, 3, 12, 6";
        return ;
    }
    if(n == 3){
        cout <<"3, 12, 6, 3";
    }
    cout << n <<"," << " ";
    if(n % 2 != 0){
        f(3 * n + 3);
    }else{
        f(n / 2);
    }
}
int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
}
