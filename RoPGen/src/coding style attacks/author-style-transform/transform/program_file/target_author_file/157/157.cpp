#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int main(){
    string s;
    vector<int> v;
    int n,sum=0,t;
    cin>>n;
    n*=60;
    while(cin>>s){
        if(s=="'tingtingting"){
            v.pop_back();
            sum=v[v.size()-1];
        }else if(s=="kaomianjin"){
            cin>>t;
            if(cin>>s&&s=="tingtingting"){
                cout<<"Hahaha."<<endl;
                return 0;
            }else{
                cout<<"Congratulations!"<<endl;
                 return 0;
            }
            
        }else{
            cin>>t;
            sum+=t;
            if(sum>=n){
                break;
            }
            v.push_back(sum);
           
        }
        
        break;
    }
   cout<<"Unfortunately."<<endl;
    
    return 0;
}

