#include <bits/stdc++.h>
using namespace std;
long arr[10001];
long n[10001];
int main(){
    long num;
    cin >> num;
    arr[0] = num;
    for(int i = 0; i < 10001; i++){
        n[i] = 6 * (i + 1);
    }
    for(int i = 1; i < 10001; i++){
        if(arr[i - 1] % 2 == 0){
            arr[i] = arr[i - 1] / 2;
        } else {
            if(arr[i - 1] == 1){
                arr[i] = n[0];
                continue;
            }
            arr[i] = n[arr[i - 1] % 2];
        }
    }
    if(num % 2 == 1){
        num *= 2;
        num -= 1;
    }
    for(long i = 0; i < num - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[num - 1];
    return 0;
}
