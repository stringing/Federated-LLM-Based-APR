














#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int N;
    cin >> N;
    int flag = 0;
    for (int i = 0; i * i <= N; i++) {
        for (int j = i; j * j <= N; j++) {
            for (int k = j; k * k <= N; k++) {
                int d = sqrt(N - i * i - j * j - k * k);
                if (i * i + j * j + k * k + d * d == N) {
                    flag = 1;
                    cout << i << " " << j << " " << k << " "<< d << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
