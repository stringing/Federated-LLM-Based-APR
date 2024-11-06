#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,k,s,m[10000][5],g=0;
int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    cin >> n;
    for(int i=0; i*i<=n; i++){
        for(int j=i; i*i+j*j<=n; j++){
            for(int r=j; i*i+j*j+r*r<=n; r++){
                k = n - i * i - j * j - r * r;
                s = sqrt(k);
                if(s*s==k){
                    g = g + 1;
                    m[g][1] = i;
                    m[g][2] = j;
                    m[g][3] = r;
                    m[g][4] = s;
                }
            }
        }
    }
    a = m[1][1];
    b = m[1][2];
    c = m[1][3];
    d = m[1][4];
    for(int i=2; i<=g; i++){
        if(a>m[i][1]||(a==m[i][1]&&b>m[i][2])||(a==m[i][1]&&b==m[i][2]&&c>m[i][3])){
            a = m[i][1];
            b = m[i][2];
            c = m[i][3];
            d = m[i][4];
        }
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}
