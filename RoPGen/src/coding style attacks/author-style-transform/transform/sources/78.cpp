#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    stack<int> a,b;
    while(n--){
        string s;
        cin>>s;
        if(s=='A'){
            string x;
            cin>>x;
            if(x=='I'){
                int data;
                cin>>data;
                a.push(data);
            }else if(x=='D'){
                if(!a.empty()){
                    a.pop();
                }
            }else{
                stack<int> c;
                while(!b.empty()){
                    c.push(b.top());
                }
                while(!c.empty()){
                    a.push(c.top());
                }
            }
        }else{
            string s;
            cin>>s;
            if(s=='A'){
                string x;
                cin>>x;
                if(x=='I'){
                    int data;
                    cin>>data;
                    b.push(data);
                }else if(x=='D'){
                   if(!b.empty()){
                        b.pop();
                   }
                }else{
                    stack<int> c;
                    while(!a.empty()){
                        c.push(a.top());
                    }
                    while(!c.empty()){
                        b.push(c.top());
                    }
                }
            }
        }
    }
    stack<int> c;
    while(!a.empty()){
        c.push(a.top());
        a.pop();
    }
    while(!c.empty()){
        cout<<c.top()<<" ";
        c.pop();
    }
    cout<<endl;
    while(!b.empty()){
        c.push(b.top());
        b.pop();
    }
    while(!c.empty()){
        cout<<c.top()<<" ";
        c.pop();
    }
    cout<<endl;
    return 0;
}

