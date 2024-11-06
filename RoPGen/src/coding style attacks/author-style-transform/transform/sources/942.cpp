#include <bits/stdc++.h>
using namespace std;
string a[105];
int main() {
    int n,r=0,l=0;
    cin >>n;
    for (int w=0;w<n;w++) {
        int k;
        cin >>k;
        if (k==1) {
            int flag=1;
            string b;
            cin >>b;
            for (int i=0;i<l;i++) {
                if (a[i][0]==b[0]) {
                    l++;
                    for (int j=l-1;j>i;j--) {
                        a[j+1]=a[j];
                    }
                    a[i+1]=b;
                    flag=0;
                    break;
                }
            }
            if (flag) {
                a[l]=b;
                l++;
            }
        } else {
            if (l==r) {
                cout <<0<<endl;
            } else {
                cout <<a[r]<<endl;
                r++;
            }
        }
    }
    return 0;
}
