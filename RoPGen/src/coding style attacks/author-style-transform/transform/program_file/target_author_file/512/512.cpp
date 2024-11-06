#include<iostream>
using namespace std;
int main(){
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    
    while (x--){
        cin >> s;
        if(s >= 'a' && s <= 'z'){
            s = 'a' + (s - 'a' + z) % 26;
        }else if(s >= 'A' && s <= 'Z'){
            s = 'A' + (s - 'A' + z) % 26;
        }else if(s >= '0' && s <= '9'){
            s = '0' + (s - '0' + z) % 10;
        }
        cout << s;
    }
}
