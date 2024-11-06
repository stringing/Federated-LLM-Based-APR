#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    string trl="Unfortunately.";
    int x;
    vector<string>s;
    vector<int>time;
    int i=1;
    string s1;
    cin>>x;
    while(cin>>s1){
        s.push_back(s1);
        if(s1!="tingtingitng"){
            int a;
            cin>>a;
            time.push_back(a);
        }
        i++;
    }i=0;
    while(x>0){
        if(i!=0&&s[i]=="tingtingting"){
            x-=time[i-1];
            if(s[i]=="kaomianjin"){
                trl="Hahaha.";
                break;
            }
        }else if(i!=s[i].size()-1&&s[i+1]!="tingtingting"){
            if(s[i]=="kaomianjin"){
                trl="Congratulations!";
                break;
            }
        }
        i++;
    }cout<<trl<<endl;
    return 0;
}
