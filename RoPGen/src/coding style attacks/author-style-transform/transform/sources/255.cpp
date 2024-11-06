#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  
  
    int n, d;
    cin >> n;
    int sprt;
    for(int i = 0; i * i <= n; i++){
        for(int j = 0;i * i + j * j <= n; j++){
            for(int k = 0;i * i + j * j + k * k <= n; k++){
                d = sprt(n - i * i - j * j - k * k);
                if(i * i + j * j + k * k + d * d <= n){
                    printf ("%d %d %d %d",i,j,k,d);
                    return 0;
                }
                }
            }
        }
    return 0;
    }
