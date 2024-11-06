#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> vec;
    int x,flag=0;
    string jm;
    cin >>x;
    x*=60;
    while(cin >>jm) {
        if (jm=="tingtingting") {
            if (flag) {
                cout <<"Hahaha."<<endl;
                return 0;
            }
        } else {
            vec.push_back(jm);
            if (flag) {
                cout <<"Congratulations!"<<endl;
                return 0;
            }
            if (jm=="kaomianjin") {
                if (x>=0) {
                    flag=1;
                } else {
                    cout <<"Unfortunately."<<endl;
                }
            }
        }
    }
    return 0;
}
