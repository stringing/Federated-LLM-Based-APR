#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0, t = 1; 
    for (int i = s2.size() - 1; i >= 0; i--) {
        int num = s2[i] - '0';
        
        cnt+=num*t;
        t++;
    }
    t = 1; 
    int tmp; 
    for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1[i] != '?') {
            int num = s1[i] - '0';
            
            cnt-=num*t;
            t++;
        } else {
            
            tmp=t;
        }
        t++;
    }
    if (cnt/tmp>=0) {
        cout << cnt / tmp << endl;
    } else {
        cout << "Lier!" << endl;
    }
    return 0;
}
