#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
void init() {
    m["10100000"] = "A";
    m["10100001"] = "B";
    m["10100010"] = "C";
    m["10100011"] = "C";
    m["10100100"] = "E";
    m["10100101"] = "F";
    m["10100110"] = "G";
    m["10100111"] = "H";
    m["10101000"] = "I";
    m["10101001"] = "J";
    m["10101010"] = "K";
    m["10101011"] = "L";
    m["10101100"] = "M";
    m["10101101"] = "N";
    m["10101110"] = "O";
    m["10101111"] = "P";
    m["10110000"] = "Q";
    m["10110001"] = "R";
    m["10110010"] = "S";
    m["10110011"] = "T";
    m["10110100"] = "U";
    m["10110101"] = "V";
    m["10110110"] = "W";
    m["10110111"] = "X";
    m["10111000"] = "Y";
    m["10111001"] = "Z";
    return;
}
int StrToInt(string s) {
    int bin = 0, dec = 0;
    for (int i = 0; i < s.size(); i++) {
        bin = bin * 10 + (s[i] - '0');
    }
    int i = 0;
    while (bin != 0) {
        int m = bin % 10;
        bin /= 10;
        dec += m * pow(2, i++);
    }
    return dec;
}
string IntToStr(int n) {
    string s = "";
    while (n) {
        string tmp = "";
        tmp[0] = (char)n % 10 + '0';
        s.insert(s.size(), tmp);
        n /= 10;
    }
    return s;
}
int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    init();
    string s, ans = "";
    cin >> s;
    if (s.size() % 8 != 0) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i += 8) {
        if (s[i] == '1') {
            if (s[i + 1] == '0' && s[i + 2] == '1') {
                if (m[s.substr(i, 8)] < "A") {
                    cout << "Error" << endl;
                    return 0;
                }
                ans.insert(ans.size(), m[s.substr(i, 8)]);
            } else if (s[i + 1] == '1' && s[i + 2] == '1') {
                ans.insert(ans.size(), " ");
            } else {
                cout << "Error" << endl;
                return 0;
            }
        } else {
            if (i + 15 >= s.size()) {
                cout << "Error" << endl;
                return 0;
            }
            if (s[i + 9] == 0) {
                cout << "Error" << endl;
                return 0;
            }
            ans.insert(ans.size(), IntToStr(StrToInt(s.substr(i, 8)) / 2 + StrToInt(s.substr(i + 9, 8)) / 2));
            i += 8;
        }
    }
    cout << ans << endl;
}
