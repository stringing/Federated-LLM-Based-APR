#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I') {
                s[i] += 32;
            }
            if (s[i] == '?') {
                s[i] = '!';
            }
        }
        string y[1005] = {};
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                y[x] += s[i];
            } else {
                x++;
            }
        }    
        for (int i = 0; i <= x; i++) {
            if (y[i] == "can" || y[i] == "could" && y[i + 1] == "you") {
                cout << "I " << y[i] << " ";
            } else if (y[i] == "I" || y[i] == "me") {
                cout << "you "; 
            } else {
                cout << y[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
