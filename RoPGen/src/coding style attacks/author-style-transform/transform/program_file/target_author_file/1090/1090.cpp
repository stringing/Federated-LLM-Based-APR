#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    string index;
    getline (cin , s);
    string number;
    int d = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            index += s[i];
        } else {
            if(d = 0){
                number = index;
                d++;
            } else {
                if(index.size() > number.size()){
                    number = index;
                    index -= '100000';
                    cout << index << endl;
                }
            }
            
        }
    }
    cout << number;
    return 0;
}
