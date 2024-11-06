#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector <int> a;
int main() {
    int s, x, n, sum = 0;
    string t;
    cin >> x;
    x *= 60;
    while (cin >> s) {
        if (s == "tingtingting") {
            a.pop_back();
            sum = a[a.size() - 1];
        } else if (s = "kaomianjin") {
            cin >> t;
            if (cin >> t && t == "tingtingting") {
                cout << "Hahaha" << endl;
                return 0;
            }
            cout << "Congratulations!" << endl;
            return 0;
        } else {
            cin >> n;
            sum += n;
            if (sum >= x) {
                break;
            }
            a.push_back(sum);
        }
    }
    cout << "Congratulations!" << endl;
    return 0;
}
