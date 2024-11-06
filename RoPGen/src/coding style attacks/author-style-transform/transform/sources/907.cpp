#include <bits/stdc++.h>
using namespace std;
int n,k,s,m[5];
int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    cin >> n;
    for(int i=0; i*i<=n; i++){
        for(int j=i; i*i+j*j<=n; j++){
            for(int r=j; i*i+j*j+r*r<=2000; r++){
                k = n - i * i - j * j - r * r;
                s = sqrt(k);
                if(s*s==k){
                    m[1] = i;
                    m[2] = j;
                    m[3] = r;
                    m[4] = s;
                    sort(m+1,m+5);
                    for(int i=1; i<=4; i++){
                        cout << m[i] << " ";
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
