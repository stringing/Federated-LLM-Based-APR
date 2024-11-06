#include <iostream>
#include <string>
using namespace std;
int main () {
    string l;
    getline(cin, l);
    int c, w = 0;
    for (int i = 0; i <= l.size(); i++){
        if (l[i] == 0){
            w = 0;
            c + 1;
        }
        cout << l << endl;
    }
    return 0;
}
