#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int N, a, b, c, d, t;
    int u = sqrt(t);
    cin >> N;
    for(int i = 0; i <= N; i++) {
        a = i;
        for (int j = 0; j <= N; j++) {
            b = j;
            for (int k = 0; k <= N; k++) {
                c = k;
                if (u * t == t && u >= k) {
                    break;
                }
            }
        }
    }
    cout << a << " " << b << " " << c " " << << t; 
    return 0;
}
