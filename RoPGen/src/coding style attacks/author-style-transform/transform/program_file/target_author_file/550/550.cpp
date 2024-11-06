#include <bits/stdc++.h>
using namespace std;
string name[105];
int front = 0, rear = 0;
int c(string x) {
    for (int i = front; i < rear; i++) {
        if (name[i] == x) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        if (k == 1) {
            cin >> name[rear];
            rear++;
            if (c(name[rear - 1]) != -1) {
                string t = name[rear - 1];
                for (int i = c(name[rear - 1]) + 1; i < rear; i++) {
                    name[i] = name[i + 1];
                }
                name[c(name[rear - 1])] = t;
            }
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
