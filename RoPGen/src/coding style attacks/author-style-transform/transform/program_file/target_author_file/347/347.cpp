#include<bits/stdc++.h>
using namespace std;

int main(){
    int op;
    cin>>op;
    stack<int> sk1,sk2;
    vector<int> vec,ans1,ans2;
    for(int i=0;i<=110;i++){
        vec.push_back(0);
    }
    while(op--){
        char c;
        cin>>c;
        char x;
        cin>>x;
        if(c=='A'){
            if(x=='I'){
                int data1;
                cin>>data1;
                sk1.push(data1);
            }else if(x=='D'){
                if(!sk1.empty()) sk1.pop();
            }else{
                int top1=0;
                while(!sk2.empty()){
                    vec[top1]=sk2.top();
                    sk2.pop();
                    top1++;
                }
                for(int i=top1-1;i>=0;i--){
                    sk1.push(vec[i]);
                }
            }
        }else{
            if(x=='I'){
                int data2;
                cin>>data2;
                sk2.push(data2);
            }else if(x=='D'){
                if(!sk2.empty()) sk2.pop();
            }else{
                int top2=0;
                while(!sk1.empty()){
                    vec[top2]=sk1.top();
                    sk1.pop();
                    top2++;
                }
                for(int i=vec.size()-1;i>=0;i--){
                    sk2.push(vec[i]);
                }
            }
        }
    }
    while(!sk1.empty()){
        ans1.push_back(sk1.top());
        sk1.pop();
    }
    while(!sk2.empty()){
        ans2.push_back(sk2.top());
        sk2.pop();
    }
    for(int i=ans1.size()-1;i>=0;i--){
        cout<<ans1[i]<<' ';
    }cout<<endl;
    for(int i=ans2.size()-1;i>=0;i--){
        cout<<ans2[i]<<' ';
    }
    return 0;
}
