#include <iostream>
using namespace std;
int main() {
    int n, x ,m,d = 1;
    char s;
    cin >> n >> x>>m;
    while (n--) {
        cin >> s;
        if (d % x == 0){   
            if (s >='a'&& s <='z'){
                s = (s - 'a'+ m) % 26+ 'a';
            }else if (s >='A'&& s <='Z'){
                s= (s - 'A' + m)% 26 +'A';
            }else if (s >='0'&& s <='9'){
                s = (s - '0'+ m)% 10 + '0';
            }
        }
        d ++;
    }
    cout << s;
    return 0;
}
