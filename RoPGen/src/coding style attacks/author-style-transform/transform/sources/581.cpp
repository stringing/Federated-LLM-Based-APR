#include<iostream>
#include<string>
using namespace std;
string a[205];
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    cin >> a[0];
    int N = a[0].size();
    cout << N << " ";
    for (int i = 1; i < N; i++) {
        cin >> a[i];
    }
    char s = 0;
    char q = 0;
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s = q;
            q = a[i][j];
            if (s == q) {
                num++;
            } else {
                cout << num << " ";
                num = 1;
            }
        }
    }
    cout << num << " ";
    return 0;
    
}
