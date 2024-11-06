#include <iostream>
#include <string>
using namespace std;
int main() {
    int sum;
    string s[105];
    cin >> s[105];
    getline(cin,s[105]);
    sum = s[105].find("0");
    for (int i = 0;i < s[105].size();i++) {
        if (s[105].find("i + 1").size() > s[105].find("i").size()) {
            sum = s[105].find("i + 1");
        }
    }
    cout << sum;
    return 0;
}
