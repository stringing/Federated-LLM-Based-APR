#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

string str;

int bina(string s) {
    int sum = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        int p = len - i - 1;
        sum += (s[i] - '0') * pow(2, p);
    }
    return sum;
} 


bool  check() {
    if (str.size() < 8) { 
        return false; 
    }
    for (int i = 0 ; i < str.size(); i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    
    for (int i = 0; i < str.size(); i+=8) {
        int m = i;
        if (str[m] == '1' && str[m + 1] == '0' && str[m + 2] == '0') {
            return false;
        }
        if (str[m] == '1' && str[m + 1] == '1' && str[m + 2] == '0') {
            return false;
        }
        if (str[m] == '1' && str[m + 1] == '0' && str[m + 2] == '1') {
            string s = str.substr(m + 3, 5);
            if (bina(s) > 25) {
                return false;
            }
        }
        if (str[m] == '0' && str[m + 8] != '0') {
            return false;
        } else{
            i+=8;
        }
    }
    return true;
}

int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    cin >> str;
    
    if (!check()) {
        cout << "Error" << endl;
        return 0;
    }
    
    for (int i = 0; i < str.size(); i+=8) {
        int m = i;
        if (str[m] == '1' && str[m + 1] == '0' && str[m + 2] == '1') {
            string s = str.substr(m + 3, 5);
            cout << (char)('A' + bina(s));
        }
        if (str[m] == '1' && str[m + 1] == '1' && str[m + 2] == '1') {
            cout << ' ';
        }
        if (str[m] == '0') {
            i += 8;
            string s1 = str.substr(m, 8);
            string s2 = str.substr(m + 8, 8);
            int num1 = bina(s1);
            int num2 = bina(s2);
            num1 /= 2, num2/= 2;
            int add = num1 + num2;
            cout << add;
        }
    }
    return 0;
}
