#include <iostream>
#include <string>
using namespace std;
string correct, ans[101];
int main() {
    string a;
    string e;
    cin >> a;
    e = a[1];
    for (int i = 0; i < a.size(); i++) {
        if (a[i].size() > e.size()) {
            e = a[i];
        }
    }
    cout << e;
    return 0;
}
