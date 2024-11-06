#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int nim = 0, max = 0, index = 0, maxIndex = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            num = 0;
            index = i + 1;
            continue;
        }else{
            num++;
        }
        if(num > max){
            max = num; 
            maxIndex = index;
        }
    }
    for(int i = 0; i < max; i++){
        cout << s[maxIndex + i];
    }
    return 0;
}
