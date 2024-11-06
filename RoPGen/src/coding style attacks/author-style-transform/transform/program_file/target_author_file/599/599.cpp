#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int num = 0,index = -1,cnt,s1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            cnt = num;
            num = 0;
            index = index + 1;
        } else {
            num++;
        }
        if (cnt >= num){
            s1 = cnt;
        } else {
            s1 = num;
        }
    }
    cout << s[index];
    return 0;
}
