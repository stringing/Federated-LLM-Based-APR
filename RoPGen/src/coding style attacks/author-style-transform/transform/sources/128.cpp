#include <iostream>
using namespace std;
int main() {
    int year;
    cin >> year;
    if (year % 100 != 0 && year % 4 == 0) {
    cout << 29;
    } else if (year % 400 == 0) {
    cout << 29;
    } else {
    cout << 28;
    }
    return 0;
}
