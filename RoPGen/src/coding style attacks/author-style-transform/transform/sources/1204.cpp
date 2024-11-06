#include <iostream>
#include <string>
using namespace std;
int main() {
    string q[105];
    int l = 0, r = 0;
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 1) {
            string name;
            cin >> name;
            q[r] = name;
            r++;
        } else if (k == 2) {
            if (l < r) {
                cout << q[l] << endl;
                l++;
            }
            else {
                cout << 0 << endl;
            }
        } else {
            string name;
            cin >> name;
            bool flag = 0;
            for (int i = l; i < r; i++) {
                if (q[i] == name) {
                    cout << i + 1 << endl;
                    for (int j = i; j < r - 1; j++) {
                        q[j] = q[j + 1];
                    }
                    r--;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
