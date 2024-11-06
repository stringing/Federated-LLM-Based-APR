#include<bits/stdc++.h>
using namespace std;
int cnt(string s){
    if(s[0] == '1' && s[1] == '1' && s[2] == '0'){
        cout << "Error";
        return 0;
    }
    if(s[0] == '1' && s[1] == '0' && s[2] == '0'){
        cout << "Error";
        return 0;
    }
    return 1;
}
int main (){
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    string n;
    cin >> n;
    int a = n.size();
    char c[a];
    string x = "";
    for(int i = 1; i <= a; i++) {
        if(a % 8 != 0){
            cout << "Error";
            return 0;
        }
        c[i] = n[i];
        x += c[i];
        if(i % 8 == 0) {
            if(n[0] == 0)
                stoi(x, 0, 2);
        }
    }
    cout << x;
    return 0;
}
