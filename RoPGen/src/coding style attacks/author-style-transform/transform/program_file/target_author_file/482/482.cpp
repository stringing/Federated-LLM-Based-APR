#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    stack<char> a, b;
    while (n--) {
        char s;
        cin >> s;
        if (s == 'A') {
            char x;
            cin >> x;
            if (x == 'I'){
                int data;
                cin >> data;
                a.push(data);
            }else if (x == 'D') {
                if (!a.empty()) {
                    a.pop();
                }
            }else {
                stack <char> c;
                while (!b.empty()) {
                    c.push(b.top());
                    b.pop();
                }
                while (!c.empty()) {
                    a.push(c.top());
                    c.pop();
                }
            }
        } else if (s == 'B') {
            char y;
            cin >> y;
            if (y == 'I'){
                int data;
                cin >> data;
                a.push(data);
            }else if (y == 'D') {
                if (!b.empty()) {
                    b.pop();
                }
            }else {
                stack <char> d;
                while (!a.empty()) {
                    d.push(a.top());
                    a.pop();
                }
                while (!d.empty()) {
                    b.push(d.top());
                    d.pop();
                }
            }
        }
    }
    stack <int> c1;
    while (!a.empty()) {
        c1.push(a.top());
        a.pop();
    }
    while (!c1.empty()) {
        cout << c1.top() << " ";
        c1.pop();
    }
    cout << endl;
    while (!b.empty()) {
        c1.push(b.top());
        b.pop();
    }
    while (!c1.empty()) {
        cout << c1.top() << " ";
        c1.pop();
    }
    cout << endl;
    return 0;
}
