#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    int n;
    string q[10001];
    cin >> n;
    int l = 0,r = 0;
    while (n--) {
        int k;
        cin >> k;
        bool flag = 0;
        if (k == 1) {
            string name;
            cin >> name;
            for (int i = l; i < r; i++) {
                if (q[i][0] == name[0]) {
                    for (int j = r; j > i + 1; j--){
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
        }
        if (k == 2) {
            if (r == 1) {
                cout << 0 << endl;
                continue;
            }
            cout << q[l] << endl;
            l++;
        }
    }
    
    return 0;
}
