#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int len,f,x,p;
char st[20000];
int change(int m) {
    int sum=0,cnt=5;
    for (int i=m*8+3;i<(m+1)*8;i++) {
        cnt--;
        if (a[i]=='1') sum+=pow(2,cnt);
    }
    return sum;
}
int main() {
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    cin >> a;
    len=a.size();
    if (len%8!=0) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i=0;i<len;i++) {
        if (a[i]!='0' && a[i]!='1') {
            cout << "Error" << endl;
            return 0;
        }
    }
    for (int i=0;i<len/8;i++) {
        if (a[i*8]=='1') {
            if (a[i*8+1]=='0' && a[i*8+2]=='1') {
                int number=change(i);
                if (number<=25) st[p++]=char(number+'A');
                else {
                    cout << "Error" << endl;
                    return 0;
                }
            } else if (a[i*8+1]=='1' && a[i*8+2]=='1') {
                st[p++]=' ';
            } else {
                cout << "Error" << endl;
                return 0;
            }
        } else {
            if (f==0) {
                x+=change(i)/2;
                f++;
            } else if (f==1) {
                f=0;
                st[p++]=char(x+change(i)/2+'0');
                x=0;
            }
        }
    }
    if (f==1) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i=0;i<p;i++) cout << st[i];
    return 0;
}
