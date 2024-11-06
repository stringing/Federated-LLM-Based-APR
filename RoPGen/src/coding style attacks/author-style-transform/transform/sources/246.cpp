#include <string>
#include <iostream>
using namespace std;
int main() {
    string s,words[100],a;
    getline(cin, s);
    int index = 0,cnt = 0,count = 0;
    for (int i = 0;i < s.size();i++) {
        cnt++;
        words[cnt] = s.substr(index,i - index);
        cnt++;
        index = i + 1;
        count++;
        }
    for (int j = 0;j < count;j++) {
        if (words[j] >= words[j + 1]) {
            a = words[j];
        } else {
            a = words[j + 1];
        }
    }
    cout << a << endl;
        return 0;
}
