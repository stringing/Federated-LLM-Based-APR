#include <iostream>
#include <string>
using namespace std;
string ans(string a) {
    while(a.find("can you") != string::npos) {
        a.replace(a.find("can you"),a.find("can you") + 7,"I can");
    }
    while(a.find("could you") != string::npos) {
        a.replace(a.find("could you"),a.find("could you") + 9,"I could");
    }
    while(a.find("I") != string::npos && (a.substr([a.find("I")],[a.find("I")] + 4) != "I can" || a.substr([a.find("I")],[a.find("I")] + 6) != "I could")) {
        a.replace(a.find("I"),a.find("I") + 1,"you");
    }
    while(a.find("me") != string::npos) {
        a.replace(a.find("me"),a.find("me") + 2,"you");
    }
    while(a.find("?" != string::npos)) {
        a.replace(a.find("?"),a.find("?") + 1,"!");
    }
    return a;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        cout << ans(s) << endl;
    }
    return 0;
}
