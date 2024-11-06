#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
    vector<int>v;
    int x;
    cin>>x;
    string s;
    int p=x*60;
    while(cin>>s){
        if(s=="tingtingting"){
            continue;
        }else if(s=="kaomianjin"){
            if(s=="tingtingting"){
                cout<<"Hahaha.";
            }else{
                cout<<"Congratulations!";
            }
        }else{
            int t,ans=0;
            cin>>t;
            v.push_back(t);
            for(int i=0;i<v.size();i++){
                ans+=v[i];
            }
            if(ans>p){
                cout<<"Unfortunately.";
            }
        }
    }
    return 0;
}
