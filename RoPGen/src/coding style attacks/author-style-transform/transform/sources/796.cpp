#include<bits/stdc++.h>
using namespace std;
string a,i;
bool f;
int len,old_temp,cnt;
int main() {
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    while (cin >> a) {
        for (int i=0;i<a.size();i++) {
            if (!f && !i) {
                old_temp=a[i];
                cnt++;
                cout << a.size() << ' ';
                f=true;
            } else if (a[i]!=old_temp) {
                cout << cnt << ' ';
                old_temp=a[i];
                cnt=1;
            } else {
                cnt++;
            }
        }
    }
    cout << endl;
    return 0;
}

