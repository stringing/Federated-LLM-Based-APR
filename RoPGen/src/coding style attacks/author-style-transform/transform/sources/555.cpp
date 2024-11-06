#include <iostream>
#include <vector>
using namespace std;
struct show {
    string s;
    int t;
};
int main() {
    int n,cnt = 0;
    cin >> n;
    n *= 60;
    vector<show> b;
    show x;
    int i = 0;
    bool y = false;
    while(cin >> x.s) {
        if(x.s != "tingtingting") {
            cin >> x.t;
            cnt += x.t;
            b.push_back(x);
        }
        if(y == true && x.s != "tingtingting") {
            cout << "Congratulations!" << endl;
            return 0;
        }
        if(x.s == "tingtingting") {
            if(y == true) {
                cout << "Hahaha." << endl;
                return 0;
            }
            cin >> x.t;
        }
        if(x.s == "kaomianjin" && cnt <= n) {
            y = true;
        }
        if(x.s == "kaomianjin" && cnt > n) {
            cout << "Unfortunately." << endl;
            return 0;
        }
        i++;
    }
}
