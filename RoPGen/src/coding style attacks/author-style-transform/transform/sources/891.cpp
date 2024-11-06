#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string q[105];
    int l = 0, r = 0;
    
    while (n--) {
        int flag = 0;
        int k;
        cin >> k;
        if (k == 1) {
            string name;
            cin >> name;
            for (int i = l; i < r; i++) {
                if (q[i][0] == name[0]) {
                    for (int j = r; i > i + 1; j--) {
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
        } else if (k == 2) {
            if (l < r) {
                cout << q[l] << endl;
                l++;
            } else {
                cout << 0 << endl;
            }
            
        }
    }
    return 0;
}
