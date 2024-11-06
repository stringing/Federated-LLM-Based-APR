#include <iostream>
using namespace std;
int main() {
int x, y, z;
    char s;
    cin >> x >> y >> z;
    while(x--){
    if(s % y == 0){
        cin >> s;
        if(s >= '0' && s <= '9'){
            cout << s = (s - '0' + z) % 10 + '0';
        }else if(s >= 'a' && s <= 'z'){
            cout << s = (s - 'a' + z) % 26 + 'a';
        }else{
            cout << s = (s - 'A' + z) % 26 + 'A';
        }else{
      continue;
        }
    }
    }
    
    return 0;
}
