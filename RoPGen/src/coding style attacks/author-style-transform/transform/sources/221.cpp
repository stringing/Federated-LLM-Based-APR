#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int a[105];
    for(int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    for(int i = n-1; i >= 0; i --){
        int b = a[i];
        int c = a[i - 1];
        int sum = 0;
        int sum1 = 0;
        while(b != 0){
            sum += b % 10;
            b /= 10;
        }
        while(c != 0){
            sum1 += c % 10;
            c /= 10;
        }
        if(sum > sum1){
            int d = a[i - 1];
            a[i-1] = a[i];
            a[i] = d;
        }
    }
    for(int i = n-1; i >= 0; i --){
        printf("%d ", a[i]);
    }
    return 0;
}
