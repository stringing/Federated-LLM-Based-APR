#include <bits/stdc++.h>
using namespace std;
long long sqr(long long n){
    return n * n;
}
int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    bool b = true;
    long long N;
    cin >> N;
    for(long long i = 0; i < 20; i++){
        for(long long j = i; j < 20; j++){
            for(long long p = j; p < 2000; p++){
                for(long long q = p; q < 2000; q++){
                    if(sqr(i) + sqr(j) + sqr(p) + sqr(q) == N){
                        b = false;
                        cout << i << " " << j << " " << p << " " << q << endl;
                        break;
                    }
                }
                if(b == false)break;
            }
            if(b == false)break;
        }
        if(b == false)break;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
