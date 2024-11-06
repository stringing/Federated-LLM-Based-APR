#include <iostream>
#include <string>
using namespace std;
string q[105];
int l = 0, r = 0;
int flag(string name) {
    for (int i = l; i < r; i++) {
        if (name[0] == q[i][0]) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        if (k == 1) {
            string name;
            cin >> name;
            if (flag(name) != -1) {
                for (int i = r; i > flag(name) + 1; i--) {
                    q[i] = q[i-1];
                }
                q[flag(name) + 1] = name;
            } else {
                q[r] = name;
            }
            r++;
        } else {
            cout << q[l] << endl;
            l++;
        }
    }
    return 0;
}
