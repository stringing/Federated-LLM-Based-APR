#include<bits/stdc++.h>
using namespace std;
int x;
struct BY{
    string name;
    int time;
};
BY a;
int ste;
int main(){


    cin>>x;
    while(cin>>a.name){
        cin>>a.time;
        if(a.name=="tingtingting"){
            continue;
        }else if(a.name=="kaomianjin"){
            if(x>=ste){
                cout<<"Congratulations!";
                return 0;
            }else if(x<ste){
                cout<<"Unfortunately.";
                return 0;
            }
        }
    }
    cout<<"Hahaha.";
    return 0;
}

