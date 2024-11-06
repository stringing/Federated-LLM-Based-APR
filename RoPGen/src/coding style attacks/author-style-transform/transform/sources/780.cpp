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
        } else {
            
            tmp=t;
        }
        t++;
    }    
    if(cnt/tmp==0||cnt/tmp==1||cnt/tmp==2||cnt/tmp==3||cnt/tmp==4||cnt/tmp==5||cnt/tmp==6||cnt/tmp==7||cnt/tmp==8||cnt/tmp==9&&cnt%tmp==0) {
        cout << cnt / tmp << endl;
    } else {
        cout << "Lier!" << endl;
    }
    return 0;
}
