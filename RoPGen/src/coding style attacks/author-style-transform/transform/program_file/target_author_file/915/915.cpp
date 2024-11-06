#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    stack <int> a, b;
    while(n--){
        char s;
        cin >> s;
        if(s == 'A'){
            char x;
            cin >> x;
            if(x == 'I'){
                int data;
                cin >> data;
                a.push(data);
            } else if(x == 'D'){
                if(!a.empty()){
                    a.pop();
                }
            } else {
                stack <int> c;
                while(!b.empty()){
                    c.push(b.top());
                    b.pop();
                }
                while(!c.empty()){
                    a.push(c.top());
                    c.pop();
                }
            }
        } else {
            char x;
            cin >> x;
            if(x == 'I'){
                int data;
                cin >> data;
                a.push(data);
            } else if(x == 'D'){
                if(!a.empty()){
                    a.pop();
                }
            } else {
                stack <int> c;
                while(!b.empty()){
                    c.push(b.top());
                    b.pop();
                }
                while(!c.empty()){
                    a.push(c.top());
                    c.pop();
                }
            }
        }
    }
}
