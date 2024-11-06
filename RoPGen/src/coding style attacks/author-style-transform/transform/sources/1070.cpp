#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main() {
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    cin >> s;
    if (s.size() % 8 != 0) {
        cout << "Error" << endl;
        return 0;
    }
    
    return 0;
}
