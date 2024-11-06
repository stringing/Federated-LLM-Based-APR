#include <bits/stdc++.h>
using namespace std;

string ns[100000];
int l = 0, r = 0;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 1) {
            string name;
            cin >> name;
            bool flag = 0;
            for (int i = l; i < r; i++) {
                if (ns[i][0] == name[0]) {
                    for (int j = r; j > i + 1; j--) {
                        ns[j] = ns[j - 1];
                    }
                    ns[i + 1] = name;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                ns[r] = name;
            }
            r++;
        } else {
            if (l == r) {
                cout << 0 << endl;
            } else {
                cout << ns[l] << endl;
            }
            l++;
        }
    }
    return 0;
}
