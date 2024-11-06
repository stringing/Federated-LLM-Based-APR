#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int mi[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128};

int count(string a) {
    int len = a.size();
    int cnt = len - 2;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '1') {
            sum += mi[cnt];
        }
        cnt--;
    }
    return sum;
}

int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    string a;
    cin >> a;
    int len = a.size();
    if (len % 8) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] != '0' && a[i] != '1') {
            cout << "Error" << endl;
            return 0;
        }
    }
    for (int i = 0; i < len; i += 8) {
        if (a.substr(i, i + 2) == "111") {
            cout << " ";
            continue;
        }
        if (a.substr(i, i + 3) == "101") {
            int x = count(a.substr(i + 3, i + 7));
            if (x >= 26) {
                cout << "Error" << endl;
                return 0;
            }
            x += 65;
            cout << (char)x;
            continue;
        }
        if (a.substr(i, i + 3) == "110" || a.substr(i, i + 3) == "100") {
            cout << "Error" << endl;
            return 0;
        }
        if (a[i] == '0') {
            if (a[i + 8] != '0') {
                cout << "Error" << endl;
                return 0;
            }
            int x1 = count(a.substr(i + 1, i + 7));
            int x2 = count(a.substr(i + 9, i + 15));
            cout << x1 + x2;
            i += 8;
            continue;
        }
    }
}
