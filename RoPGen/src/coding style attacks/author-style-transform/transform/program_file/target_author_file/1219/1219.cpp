#include<iostream>
#include<vector>
using namespace std;
int allt,sum,t;
vector<int> v;
string s;
int main(){
    cin>>allt;
    allt*=60;
    while(cin>>s){
    if(s=="tingtingting"){
        v.pop_back();
       sum=v[v.size()-1]; 
    }
        else if(s=="kaomianjin"){
            cin>>t;
          if(cin>>s&&s=="tingtingting"){
              cout<<"Hahaha";
              return 0;
          }
            cout<<"Congratulations!";
            return 0;
        }
        else{
            cin>>t;
            sum+=t;
            if(sum>t) break;
            v.push_back(sum);
        }
    }
    cout<<"Unfortunately";
return 0;
}
