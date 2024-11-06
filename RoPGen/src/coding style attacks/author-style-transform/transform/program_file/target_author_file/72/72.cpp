#include <bits/stdc++.h>
using namespace std;
struct haha {
    string name;
    int time;
};
int main(){
    int n , t;
    string m;
    cin >> n;
    vector<haha> h;
    while (cin >> m) {
        if (m != "tingtingting") {
            cin >> t;
        } else {
            t = 0;
        }
        h.name.push_back(m);
        h.time.push_back(t);
    }
    for (int i = 0; i < h.size(); i++) {
        if (h[i].name != "kaomianjin" && h[i + 1].name != "tingtingting") {
            n -= h[i].time;
        }
        if (h[i].name == "kaomianjin" && h[i + 1].name == "tingtingting") {
            cout << "Hahaha." << endl;
            return 0;
        }
        if (h[i].name == "kaomianjin" && n >= 0 && h[i + 1].name != "tingtingting") {
            cout << "Congratulations!";
            return 0;
        }
    }
    cout << "Unfortunately." << endl;
    return 0;
}
