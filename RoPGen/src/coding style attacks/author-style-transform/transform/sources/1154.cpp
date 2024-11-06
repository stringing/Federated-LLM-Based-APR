#include <bits/stdc++.h>
using namespace std;
int main() {
    int op;
    int n;
    cin >> n;
    string q[105];
    int l = 0 , r = 0;
    while (n--) {
        cin >> op;
        if (op == 1) {
            string name;
            cin >> name;
            int flag = 0;
            for (int i = l; i < r; i++) {
                if (q[i][0] == name[0]) {
                    for (int j = r; j > i + 1; j--) {
                        q[j] = q[j - 1];
                    }
                    q[i + 1] = name;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                q[r] = name;
            }
            r++;
        } else {
            if (r >= l) {
                cout << q[l] << endl;
                l++;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
