#include<bits/stdc++.h>
using namespace std;
string s1;
int x,n,sum;
bool flag=true;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    n*=60;
    while(true){
        if(flag){
            if(!(cin>>s1>>x)){
                return 0;
            }
        }
        sum+=x;
        if(sum>n){
            cout<<"Unfortunately.";
            return 0;
        }
        if(s1=="kaomianjin"){
            if(cin>>s1){
                if(s1=="tingtingting"){
                    cout<<"Hahaha";
                    return 0;
                }
            }
            cout<<((sum>n)? "Unfortunately.":"Congratulations!");
            return 0;
        }
        if(!(cin>>s1)){
            return 0;
        }
        if(s1=="tingtingting"){
            sum-=x;
            flag=true;
        }else{
            cin>>x;
            flag=false;
        }
    }
}
