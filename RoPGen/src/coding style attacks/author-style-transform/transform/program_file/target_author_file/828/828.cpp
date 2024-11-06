#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    string n;
    cin >> n;
    if(n[0] == '1' && n[1] == '1' && n[2] == '0'){
        cout << "Error";
        return 0;
    }
    if(n[0] == '1' && n[1] == '0' && n[2] == '0'){
        cout << "Error";
        return 0;
    }
    int a = n.size();
    if(a % 8 != 0){
        cout << "Error";
        return 0;
    }
    return 0;
}
