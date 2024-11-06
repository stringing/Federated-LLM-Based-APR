#include <iostream>
#include <string>
using namespace std;
int main (){
    int asd = 0;
    string s;

    int a = 1;
    getline(cin ,s);
    int max = 0;
    for(int i = 0;i < s.size();i++){
       
        if(s[i] >= 'a'&& s[i] <= 'z'||s[i] >= 'A' && s[i] <='Z'){
            a++;
        }
        if(s[i] == ' '){
            a = 0;
        }
        if(a > max){
            max = a;
            asd = i;
        }
    }
    cout << a[asd] << endl;
    return 0;
}
