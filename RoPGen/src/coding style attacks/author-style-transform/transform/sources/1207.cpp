#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    int min = 0; 
    getline(cin, a);
    while (a.size() != 1) {
        int k;
        k = a.find(' ');
        string b = a.substr(0, k);
        a.replace(0, k - 1, "");
        if (b.size() >= min) {
            min = b.size();
            cout << min;
        }
    }
    return 0;
}
