#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int t;
};
int main() {
    int n , sum = 0 , t;
    vector <int> a;
    cin >> n;
    node x;
    string s;
    while (cin >> x.name) {
        if (x.name == "tingtingting") {
            a.pop_back();
            sum = a[a.size() - 1];
        } else if (x.name == "kaomianjin") {
            cin >> t;
            if (cin >> s && s == "tingtingting") {
                cout << "Hahaha." << endl;
                return 0;
            }
            cout << "Congratulations!" << endl;
            return 0;
        } else {
            cin >> t;
            sum += t;
            if (sum > n * 60) break;
        }
    }
    if (sum > n) cout <<"Unfortunately." << endl;
    return 0;
}