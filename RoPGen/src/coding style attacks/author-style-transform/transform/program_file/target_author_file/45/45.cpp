#include <iostream>
#include <algorithm>
using namespace std;
int shu(int a, int b){
    int suma = 0, sumb;
    while(a != 0){
        suma += a % 10;
        a /= 10;
    }
    while(b != 0){
        sumb += b % 10;
        b /= 10;
    }
    if(suma > sumb){
        return a > b;
    } else if(suma == sumb){
        if(a > b){
            return a > b;
        } else {
            return a < b;
        }
    } else {
        return a < b;
    }
}
int main(){
    int n, x;
    cin >> n;
    int a[10000];
    x = n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(x--){
        sort(a, a + n, shu);
    }  
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
