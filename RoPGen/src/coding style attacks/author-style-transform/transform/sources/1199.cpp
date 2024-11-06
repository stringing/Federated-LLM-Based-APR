#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int cnt = 0, ans = 0, arr = 0;
    for (int i = 0; i < s.size(); i++){ 
        if (s[i] == ' '){
            if (cnt > ans){
            ans = cnt;
            arr = i - ans - 1;
            }
            cnt = 0;
        } else {
            cnt++;
        }
            }
    if (cnt > ans){
        ans = cnt;
        arr = s.size() - ans - 1;
    }
    for (int i = arr; i < ans + arr + 1; i++){
         cout << s[i];
    }
    return 0;
}
