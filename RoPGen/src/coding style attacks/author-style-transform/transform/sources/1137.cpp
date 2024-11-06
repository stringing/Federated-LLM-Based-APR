#include <iostream>
using namespace std;
int main() {
    int q[105];
    int n, m;
    cin >> n >> m;
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int flag = 0;
        for (int j = l; j < r; j++) {
            if (q[j] == x){
                flag = 1;
                break;
            }
        }
        if (!flag) {
            if(r - l < m){
                q[r] = x;
                r++;
            } else {
                l++;
                q[r] = x;
                r++;
            }
        }
    }
    for (int i = l;i < r; i++) {
        cout << q[i] << endl;
    }
    
    return 0;
}
