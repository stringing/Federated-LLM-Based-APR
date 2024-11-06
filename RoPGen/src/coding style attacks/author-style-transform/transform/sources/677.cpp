#include <iostream>
#include <string>
using namespace std;

int main() {
    string a[], c = "a";
    getline(cin, a);
    for(int i = 0;i < a.size(); i++){
        if(a[i].size > c.size){
            c = a[i];
        }
    }
    cout << c;
    return 0;
}
