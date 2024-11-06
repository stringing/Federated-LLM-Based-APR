#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, words[100], max;
    int cnt = 0, index = 0;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') {
            words[cnt] = a.substr(index, i);
            cnt++;
            index = i + 1;
        } else if (i == a.size() - 1) {
            words[cnt] = a.substr(index, i);
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (i == 0) {
            max = words[i];
        } else if (words[i].size() > max.size()) {
            max = words[i].size();
        }
    }
    cout << max << endl;
    return 0;
}
