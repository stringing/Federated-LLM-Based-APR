#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    int suma = 0,sumb = 0;
    while(a != 0){
        suma += a % 10;
        a /= 10; 
    }
    while(b != 0){
        sumb += b % 10;
        b /= 10;
    } 
    if(suma > sumb){
        return false;
    }else if(suma < sumb){
        return true;
    }else{
        return !(a < b);
    }
}
int main(){
    int n,z[110];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> z[i];
    }
    sort(z,z + n,cmp);
    for(int i = 0; i < n; i++){
        cout << z[i] << " ";
    }
    return 0;
}
