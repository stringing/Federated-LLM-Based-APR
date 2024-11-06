#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int q;
    stack<int>a,b,c;
    while(n--){
        char s;
        cin>>s;
        if(s=='A'){
            cin>>s;
            if(s=='I'){
                cin>>q;
                a.push(q);
            }
            else if(s=='D'){
                if(!a.empty()){
                    a.pop();
                }
            }
            else{
                while(!b.empty()){
                    c.push(b.top());
                    b.pop();
                }
                while(!a.empty()){
                    c.push(a.top());
                    a.pop();
                }
            }
        }
        else{
            cin>>s;
            if(s=='I'){
                cin>>q;
                b.push(q);
            }
            else if(s=='D'){
                if(!b.empty()){
                    b.pop();
                }
            }
            else{
                while(!a.empty()){
                    c.push(a.top());
                    a.pop();
                }
                while(!b.empty()){
                    c.push(b.top());
                    b.pop();
                }
            }
        }
    }
    while(!a.empty()){
        c.push(a.top());
        a.pop();
    }
    while(!c.empty()){
        b.push(c.top());
        c.pop();
    }
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
    
    while(a.size()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
    while(!b.empty()){
        c.push(b.top());
        b.pop();
    }
    while(!c.empty()){
        a.push(c.top());
        c.pop();
    }
    while(!a.empty()){
        c.push(a.top());
        a.pop();
    }
    while(b.size()){
        cout<<b.top()<<" ";
        b.pop();
    }
}
