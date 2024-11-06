#include <bits/stdc++.h>
using namespace std;
string name[105];
int front = 0, rear = 0;
int c(char x) {
    for (int i = front; i < rear; i++) {
        if (name[i][0] == x) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k = 0, f = 0;
        cin >> k;
        if (k == 1) {
            string s;
            cin >> s;
            if (c(s[0]) != -1) {
                string t = s;
                for (int j = c(s[0]) + 1; j < rear; j++) {
                    name[j] = name[j - 1];
                }
                f = 1;
            }
            if (f == 0) {
                name[rear] = s;
            }
            rear++;
        } else {
            if (front == rear) {
                cout << 0 << endl;
            } else {
                cout << name[front] << endl;
                front++;
            }
        }
    }
    return 0;
}
