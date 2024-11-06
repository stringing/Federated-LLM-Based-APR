#include <bits/stdc++.h>
using namespace std;
int x;
vector<int> a;
vector<string> s;
int main(){
    cin >> x;
    int y;
    string c;
    int i = 1;
    while(cin >> c){
        s.push_back(c);
        if(s[i] != "tingtingting"){
            cin >> y;
            a.push_back(y);
        }else{
            a.push_back(0);
        }
    }
    for (int i = 0;i < a.size();i++){
        if(s[i] != "kaomianjin"){
            x -= a[i];
            if(x < 0){
                cout << "Unfortunately";
                return 0;
            }
        } else {
            if(x -= a[i] >= 0){
                cout << "Congratulations";
                return 0;
            } else {
                cout << "Hahaha";
            }
        }
    }
}
