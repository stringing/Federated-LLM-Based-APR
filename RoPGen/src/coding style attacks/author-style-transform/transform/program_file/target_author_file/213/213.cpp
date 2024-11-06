#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s1,s2;
    int n;
    cin>>n;
    while(n--){
        char op1,op2;
        cin>>op1>>op2;
        if(op1=='A'){
            if(op2=='I'){
                int temp;
                cin>>temp;
                s1.push(temp);
            }else if(op2=='D'){
                if(s1.size()) s1.pop();
            }else{
                while(s2.size()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }else if(op1=='B'){
            if(op2=='I'){
                int temp;
                cin>>temp;
                s2.push(temp);
            }else if(op2=='D'){
                if(s2.size()) s2.pop();
            }else{
                while(s1.size()){
                    s2.push(s1.top());
                    s2.pop();
                }
            }
        }
    }
    stack<int> a,b;
    while(s1.size()){
        a.push(s1.top());
        s1.pop();
    }
    while(s2.size()){
        b.push(s2.top());
        s2.pop();
    }
    while(a.size()){
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
    while(b.size()){
        cout<<b.top()<<" ";
        b.pop();
    }
    return 0;
}
