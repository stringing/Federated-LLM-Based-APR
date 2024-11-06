#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int num = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z') {
            num++;
            if (s[i] == ' ') {
                num = 0;
            }
        }
    }
    cout << s;
    return 0;
}

