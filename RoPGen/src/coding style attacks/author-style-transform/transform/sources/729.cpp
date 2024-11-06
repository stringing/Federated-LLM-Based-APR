#include<bits/stdc++.h>
using namespace std;
stack<int> sta,stb,st;
char c[5];
int main(){
    int n;
    cin>>n;
    while(n--){
        scanf("%s",c);
        if(c[0]=='A'){
            scanf("%s",c);
            if(c[0]=='I'){
                int x;
                scanf("%d",&x);
                sta.push(x);
            }else if(c[0]=='D'){
                sta.pop();
            }else if(c[0]=='M'){
                while(!stb.empty()){
                    st.push(stb.top());
                    stb.pop();
                }
                while(!st.empty()){
                    sta.push(st.top());
                    st.pop();
                }
            }
        }
        if(c[0]=='B'){
            scanf("%s",c);
            if(c[0]=='I'){
                int x;
                scanf("%d",&x);
                stb.push(x);
            }else if(c[0]=='D'){
                stb.pop();
            }else if(c[0]=='M'){
                while(!sta.empty()){
                    st.push(sta.top());
                    sta.pop();
                }
                while(!st.empty()){
                    stb.push(st.top());
                    st.pop();
                }
            }
        }
    }
    while(!sta.empty()){
        st.push(sta.top());
        st.pop();
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    while(!stb.empty()){
        st.push(stb.top());
        st.pop();
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}
