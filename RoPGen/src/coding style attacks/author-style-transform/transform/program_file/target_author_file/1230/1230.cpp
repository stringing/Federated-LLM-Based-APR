#include <iostream>
using namespace std;
int main() {
    int x, y,z,cnt=0;
    char s;
    cin >> x >> y >>z;
    while (x--) {
        cin >> s;
       
    if(cnt %y==0) {
       if('A'<=s && s <='Z'){
           s=(s-'A'+x) %26 +'A';
    }  else if('a'<=s && s <='z' ){
           s=(s-'a'+x) %26 +'a';
    }  else if('0'<=s && s<='9'){
           s=(s-'0'+x) %10 +'0';
    }
    }
        cout<<s;
    }   
    return 0;
}

  
