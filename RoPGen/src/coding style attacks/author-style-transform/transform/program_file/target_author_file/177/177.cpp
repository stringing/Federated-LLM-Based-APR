#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    string m[205], k;
    int no = 1;
    char p = '0';
    cin >> m[0];
    k += m[0];
    for(int i = 1;i < m[0].size();i++){
        cin >> m[i];
        k += m[i];
    }
    cout << m[0].size() << " ";
    for(int i = 0;i < k.size();i++){
        if(k[i] == p){
            no++;
        } else {
            cout << no << " ";
            if(p == '0'){
                p = '1';
            } else {
                p = '0';
            }
            no = 1;
        }
    }
    cout << no;
    return 0;
}
