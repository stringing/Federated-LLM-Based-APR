#include <iostream>
using namespace std;
int main() {
    int x, y, z ,cnt=1;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if(cnt%y==0){
            if(s>='A'&&s<='Z'){
                cout<<(char)(s-'A'+z)%26;
            }
            else if(s>='a'&&s<='z'){
                cout<<(char)(s-'a'+z)%26;
            }
            else if(s>='0'&&s<='9'){
                cout<<(char)(s-'0'+z)%10;
            }
        }
        else{
            cout<<s;
        }
        cnt++;
    }
    return 0;
}

