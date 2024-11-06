#include <iostream>
using namespace std;
int main() {
    int x,y,z,sum=0;
    char s;
    cin >>x>>y>>z;
    while (x--) {
        cin >> s;
        sum++;
        if(sum%y==0){
            if(s>='A'&&s<='Z'){
                s=(s-'A'+z)%26+'A';
            }
            if(s>='a'&&s<='z'){
                s=(s-'a'+z)%26+'a';
            }
            if(s>=1&&s<=9){
                s=(s-'0'+z)%10+'0';
            }
        }
         cout<<s;
    }
    return 0;
}
