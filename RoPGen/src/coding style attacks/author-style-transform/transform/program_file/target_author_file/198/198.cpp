#include <iostream>
#include <stack>
#include <string>
#include<algorithm>
using namespace std;
int main() {
    stack<int>s1;
    stack<int>s2;
    char a,b;
    int c;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a=='A'){
            if(b=='I'){
                cin>>c;
                s1.push(c);
            }else if(b=='D'){
                if(!s1.empty()){
                    s1.pop();
                }
            }else{
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }else{
           if(b=='I'){
                cin>>c;
                s2.push(c);
            }else if(b=='D'){
                if(!s2.empty()){
                    s2.pop();
                }
            }else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            } 
        }
    }
    stack<int>st1,st2;
    while(!s1.empty()){
        st1.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        st2.push(s2.top());
        s2.pop();
    }
    while(!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;
    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    return 0;
}
