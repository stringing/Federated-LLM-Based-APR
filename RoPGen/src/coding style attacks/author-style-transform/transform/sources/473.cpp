#include <iostream>
#include <string>
using namespace std;
int main (){
    string a;
    getline(cin, a);
    long long q = 0;
    string w = "a";
    for (int i = 0; i < a.size() + 100; i++){
        if (a[i] == ' '&&a[i + 1] != ' '){
           if (a.substr(q, a.find(' ')) > w){
               w = a.substr(q, a.find(' '));
           }
        }
        a.replace(0, a.find(' ') + 1, "");
    }
    cout << a;
    return 0;
}
