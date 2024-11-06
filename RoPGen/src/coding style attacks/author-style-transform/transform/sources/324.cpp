#include <iostream>
#include <algorithm>
using namespace std;
int sum(int n) {
    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt += n % 10;
    }
    return cnt;
}
bool cmp(int x , int y){
    if (sum(x) != sum(y)) {
        return sum(x) < sum(y);
    }
    else if (sum(x) == sum(y)) {
        return x < y;
    }
}
int main() {
    string s[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s[0] , s[n - 1] , cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    return 0;
}
