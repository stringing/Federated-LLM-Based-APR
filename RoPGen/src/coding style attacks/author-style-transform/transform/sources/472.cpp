#include <iostream>
#include <string>
using namespace std;
int main (){
    string a;
    getline(cin, a);
    long long q = 0;
    string w = "a";
    for (int i = 0; a.size() >= 0; i++){ 
        if (a[i] == ' '&&a[i + 1] != ' '){
           if ((a.substr(q, a.find(' '))).size() > w.size()){
               w = a.substr(q, a.find(' '));
           }
        }
        a.replace(0, a.find(' ') + 1, "");
    }
    cout << w;
    return 0;
}
