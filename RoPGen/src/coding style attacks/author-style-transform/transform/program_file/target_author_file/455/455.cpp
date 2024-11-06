#include <iostream>
using namespace std;
int main() {
    int x,y,z;
    char s;
    int i=0;
    cin >>x>>y>>z;
    while (x--) {
        cin >> s;  
        i++;
        if(i%y==0){
            if(s>='a'&&s<='z'){
            s=(char)('a'+(s-'a'+x)%26);
}
        else if(s>='A'&&s<='Z'){
            s=(char)('A'+(s-'A'+x)%26);
        }
        else if(s>='0'&&s<='9'){
            s=(char)('0'+(s-'0'+x)%10);
        }
        }

        cout<<s;
    }
    return 0;
}
