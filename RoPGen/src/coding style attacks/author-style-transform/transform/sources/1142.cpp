#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> a;
    stack<int> b;
    while(n--){
        char s;
        cin>>s;
        if(s=='A'){
           char d;
           cin>>d;
           if(d=='I'){
              int data;
              cin>>data;
              a.push(data);
           }else if(d=='D'){
              if(!a.empty()){
                 a.pop();
              }
           }else{
              stack<int> c;
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
        if(s=='B'){
           char d;
           cin>>d;
           if(d=='I'){
              int y;
              cin>>y;
              b.push(y);
           }else if(d=='D'){
              if(!a.empty()){
                 b.pop();
              }
           }else{
              stack<int> c;
              while(!a.empty()){
                  c.push(a.top());
                  a.pop();
              }
              while(!c.empty()){
                 b.push(c.top());
                 c.pop();
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
    return 0;
}
