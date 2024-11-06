#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
int main(){
    string s;
    int time,sum = 0,t,i=0;
    cin>>time;
    time*=60;
    while(cin>>s){
        if(v[i] <=time){
            if(s == "tingtingting"){
                v.pop_back();
                sum = v[v.size()-1];
                i--;
            }else if(s == "kaomianjin"){
                cin>>t;
                if(cin>>s && s == "tingtingting"){
                    cout<<"Hahaha."<<endl;
                    return 0;
                }else{
                    cout<<"Congratulations!"<<endl;
                    return 0;
                }
            }else{
                cin>>t;
                v.push_back(sum+t);
                sum+=t;
                i++;
            }
            
        }
    }
    cout<<"Unfortunately."<<endl;
    return 0;
}
