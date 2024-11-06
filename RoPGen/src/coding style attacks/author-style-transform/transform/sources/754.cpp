#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    string s;
    int t,allt,sum=0;
    cin>>allt;
    allt*=60;
    while(cin>>s) {
        if(s=="tintgtingting"){
            v.pop_back();
            sum=v[v.size()-1];
        }else if(s=="kaomianjin"){
            cin>>t;
            if(cin>>s && s=="tingtingting"){
                cout<<"Hahaha."<<endl;
                return 0;
            }
            cout<<"Congratulations!"<<endl;
            return 0;
        }
        else{
            cin>>t;
            sum+=t;
            if(sum>=allt){
                break;
            }
            v.push_back(sum);
        }
    }
    cout<<"Unfortunately."<<endl;
    return 0;
}



