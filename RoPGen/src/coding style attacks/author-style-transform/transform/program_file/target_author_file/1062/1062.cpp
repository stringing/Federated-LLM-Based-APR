#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if (s>='a'&& s<='z'){
        s = (s-'a'+x)%26+z;
    }
    if (s>='A'&& s<='Z'){
        s = (s-'A'+x)%26+z;
    }
if (s>='0'&&s<='9'){
    s =(s-'0'+x)%10+z;
}}
    
    return 0;
}
