#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, words[100], max;
    int cnt = 0, index = 0, maxIndex;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') {
            cnt = 0;
            index = i + 1;
            continue;
        } else {
            cnt++;
        }
        if (cnt > max.size()) {
            max = cnt;
            maxIndex = index;
        }
    }
    cout << a[maxIndex] << endl;
    cout << max << endl;
    return 0;
}
