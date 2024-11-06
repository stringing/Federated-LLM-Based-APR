#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    stack<int> a, b;
    while (n--) {
        int op1;
        cin >> op1;
        if (op1 == 'A') {
            int op2;
            cin >> op2;
            if (op2 == 'I') {
                int data;
                cin >> data;
                a.push(data);
            } else if (op2 == 'D') {
                if (!a.empty()) {
                    a.pop();
                } 
            } else {
                stack<int> c;
                while (!b.empty()) {
                    c.push(b.top());
                    b.pop();
                }
                while (!c.empty()) {
                    a.push(c.top());
                    c.pop();
                }
            }
        } else {
            int op2;
            cin >> op2;
            if (op2 == 'I') {
                int data;
                cin >> data;
                b.push(data);
            } else if (op2 == 'D') {
                if (!b.empty()) {
                    b.pop();
                } 
            } else {
                stack<int> c;
                while (!a.empty()) {
                    c.push(a.top());
                    a.pop();
                }
                while (!c.empty()) {
                    b.push(c.top());
                    c.pop();
                }
            }
        }
    }
    string ansa, ansb;
    while (!a.empty()) {
        ansa += a.top();
        a.pop();
    }
    while (!b.empty()) {
        ansb += b.top();
        b.pop();
    }
    for (int i = ansa.size() - 1; i >= 0; i--) {
        cout << ansa[i] << " ";
    }
    cout << endl;
    for (int i = ansb.size() - 1; i >= 0; i--) {
        cout << ansb[i] << " ";
    }
    return 0;
}
