#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> a;
    stack<int> b;
    for(int i=0;i<n;i++){
        char c,d;
        cin>>c>>d;
        if(d=='I'){
            int k;
            cin>>k;
            if(c=='A'){
                a.push(k);
            }else{
                b.push(k);
            }
        }else if(d=='D'){
            if(c=='A'){
                a.pop();
            }else{
                b.pop();
            }
        }else {
            stack<int> e;
            while(!b.empty()){
                e.push(b.top());
                b.pop();
            }while(!e.empty()){
                a.push(e.top());
                e.pop();
            }
        }
    }stack<int> g;
    while(!a.empty()){
        g.push(a.top());
        a.pop();
    }
    while(!g.empty()){
        cout<<g.top()<<" ";
        g.pop();
    }
    cout<<endl;
    while(!b.empty()){
        g.push(b.top());
        b.pop();
    }while(!g.empty()){
        cout<<g.top()<<" ";
        g.pop();
    }
    return 0;
}
