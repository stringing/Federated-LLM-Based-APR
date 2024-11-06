#include <iostream>
using namespace std;
int main() {
    int x, y, z,a = 0;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        a ++;
        if (a % 2 == 0){
           if (s >= 'A' && s <= 'Z'){
                s = (char)('A' + (s - 'A' + x) % 26);
                cout << s;
            }else if (s >= 'a' && s <= 'z'){
                s = (char)('a' + (s - 'a' + x) % 26);
                cout << s;
            }else if(s >= '0' && s <= '9') {
                s = (char)('0' + (s - '0' + x) % 10);
                cout << s; 
            }
    
        }else{
            cout << s;
        }
    }
    return 0;
}
