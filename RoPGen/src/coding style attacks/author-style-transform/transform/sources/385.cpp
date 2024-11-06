#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    while (x--) {
        cin >> s;
        if(x%y==0){
        if(s>='A'&&s<='Z'){
            s='A'+(s-'A'+z)%26;
        }
       else if(s>='a'&&s<='z'){
            s='a'+(s-'a'+z)%26;
        }
        else {
            s=(s-'0'+z)%10+'0';
        }
        }
            
        cout<<s;
    }
    return 0;
}
