#include <iostream>
#include <string>
using namespace std;
int main (){
    string s;
    string b;
    getline(cin ,s);
    for(int i = 0;i < s.size();i++){
        if(s[i] > b){
            b = s[i];
        }
    }
    cout << b << endl;
    return 0;
}
