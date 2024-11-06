#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> name;
    vector<int> min;
    int t,tot = 0;
    cin >> t;
    t *= 60;
    string x;
    int i = 0;
    while(cin >> x) {
        name.push_back(x);    
        if(x != "tingtingting") {
            int time;
            cin >> time;
            min.push_back(time);
            tot += time;
        } else {
            tot -= time;
        }
    }
    for(i = 0;i < name.size();i++) {
        x = name[i];
        if(x == "kaomianjin") {
            if(name[i+1] == "tingtingting") cout << "Hahaha.";
            else if(tot <= t) cout << "Congratulations!";            
            else cout << "Unfortunately.";           
        }
    }
    return 0;
}
