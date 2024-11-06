#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    while(x--){
        cin>>s;
        if(s%y==0)
        {
            else if(s>='A'&&s<='Z'){
            
               s=(s-'0'+z)%26+'0'; 
}
            else if(s>='a'&&s<='z'){
                s=(s-'0'+z)%26+'0';
            }
            else if(s>='0'&&s<='9'){
                s=(s-'0'+z)%10+'0';
            }
            
}
        cout<<s;
    }
    
    return 0;
}
