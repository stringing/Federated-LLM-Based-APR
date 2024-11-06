#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if(x%2==0)｛
        if(s>='A'&&s<'Z'-x){
            s+=x;
        }else if(s>='Z'-x&&s<='Z'){
            s-=26-x;
        }
        else if(s>='a'&&s<'z'-x){
            s+=x;
        }else if(s>='z'-x&&s<='z'){
            s-=26-x;
        }else if(s>='0'&&s<'9'-x){
            s+=x;
        }else if(s>='9'-x&&s<='9'){
            s-=10-x;
        }cout<<s;}
        else {cout<<s;}
    }
    return 0;
}
