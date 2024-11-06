#include <bits/stdc++.h>
using namespace std;
struct stu{
    string str;
    int time;
};
int main(){
    stu s[100001];
    vector<string> vec;
    int x;
    cin>>x;
    int cnt=0,i=0;
    while(cnt<=x){
        cin>>s[i].str;
        vec.push_back(s[i].str);
        if(vec[i]!="tingtingting"){
            cin>>s[i].time;
            cnt+=s[i].time;            
        }
        else if(vec[i]=="tingtingting"&&vec[i-1]=="kaomianjin"){
            cout<<"Hahaha.";
            return 0;
        } 
        i++;
    }
    for(int i=0;i<vec.size();i++){
        if((vec[i]=="kaomianjin"&&i+1==vec.size())||(vec[i]=="kaomianjin"&&vec[i+1]!="tingtingting")){
            cout<<"Congratulations!";
            return 0;
        }
    }
    cout<<"Unfortunately.";
    return 0;
}
