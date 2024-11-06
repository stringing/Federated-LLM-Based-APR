#include <iostream>
#include <string>
using namespace std;
int main (){
    int max = 0, cnt = 0, flag = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++){
        if (s[i].find(" ") == string::npo){
            cnt++;
        }else {
            cnt = 0;
        }
        if (cnt > max){
            max = cnt;
            flag = i;
        }
    }
    s.substr(flag - max, max);
    cout << s;
    return 0;
}
