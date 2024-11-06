#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("bigadd.in","r",stdin);
    freopen("bigadd.out","w",stdout);
    string s;
    cin >> s;
    int a[25];
    for(int i = 0;i < s.size();i++) a[i] = s[i] - '0';
    a[s.size()-1] += 8;
    if(a[s.size()-1] >= 10) {
        a[s.size()-1] -= 10;
        a[s.size()-2] += 2;
        if(a[s.size()-2] >= 10) {
            a[s.size()-2] -= 10;
            a[s.size()-3]++;
            if(a[s.size()-3] >= 10) {
                a[s.size()-3] -= 10;
                a[size()-4]+=2;
                if(a[s.size()-4] >= 10) {
                    a[s.size()-4] -= 10;
                    a[s.size()-5]++;
                    for(int i = 5;i < s.size();i++) {
                        if(a[s.size()-i] >= 10) {
                            a[s.size()-i] -= 10;
                            a[s.size()-i+1]++;
                        }
                    }
                    
                }
            }
        }
    }
    else {
        a[s.size()-1] -= 10;
        a[s.size()-2] += 2;
        if(a[s.size()-2] >= 10) {
            a[s.size()-2] -= 10;
            a[s.size()-3]++;
            if(a[s.size()-3] >= 10) {
                a[s.size()-3] -= 10;
                a[size()-4]+=2;
                if(a[s.size()-4] >= 10) {
                    a[s.size()-4] -= 10;
                    a[s.size()-5]++;
                    for(int i = 5;i < s.size();i++) {
                        if(a[s.size()-i] >= 10) {
                            a[s.size()-i] -= 10;
                            a[s.size()-i+1]++;
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}
