#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> name;
    int t,tot = 0;
    cin >> t;
    t *= 60;
    string x;
    int i = 0;
    while(cin >> x) {
        if(x != "tingtingting") {
            name.push_back(x);    
            int time;
            cin >> time;
            tot += time;
        }
        if(x == "kaomianjin") {
            if(tot <= t) cout << "Congratulations!";            
            else if(name[i+1] == "tingtingting") cout << "hahaha.";
            else cout << "Unfortunately.";           
        }
        i++;
    }
    return 0;
}
