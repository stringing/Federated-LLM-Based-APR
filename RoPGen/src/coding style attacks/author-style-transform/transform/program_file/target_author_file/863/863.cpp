#include <bits/stdc++.h>
using namespace std;
int cmp (int a, int b) {
    int suma = 0, sumb = 0;
    int aa = a, bb = b;
    while (aa > 0) {
        suma += aa % 10;
        aa /= 10;
    }
    while (bb > 0) {
        sumb += bb % 10;
        bb /= 10;
    }
    if (suma < sumb) {
        return a < b;
    } else if (suma > sumb) {
        return a > b;
    } else {
        return a < b;
    }
}
int main () {
    int n;
    cin >> n;
    int x[100];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    return 0;
}
