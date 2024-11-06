#include <iostream>
using namespace std;
int main() {
    int x, y, z;
    char s;
    cin >> x >> y >> z;
    int i = 0;
    while (x--) {
        cin >> s;
        if(x%2==1){
            if(s >= 'A' && s <= 'Z'-y){
                s+=y;
            }else if(s >='a' && s <='z'-y){
                s+=y;
            }else if(s >='0' && s <='9'-y){
                s+=y;
            }else if(s >='0'+y){
                s=s-10+y;
            }
            cout << y;
        }else{
            cout << s;
       }
        
    }
    return 0;
}
