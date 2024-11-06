#include<vector>
#include<iostream>
#include<string>
using namespace std;
int min(){
    int x;
    cin >> x;
    x = x * 60;
    vector<int> v;
    string cvz;
    int i = 0;
    int u = 0;
    while(cin >> cvz){
        if(cvz[u]== "tingtingting"){
            continue;
        }
        else{
        cin >> v[u];
        }
        u=u+1;
    }
    while(x>= 0){
        if(cvz[i] == "kaomianjin"){
            if(cvz[i+1]=="tingtingting"){
                cout << "Hahaha.";
                return 0;
            }else{
                cout << "Congratulations!";
                return 0;
            }
        }else{
            if(cvz[i+1] == "tingtingting"){
                continue;
            }else{
                x = x - v[i];
            }
    }
        i = i + 1;
    }
    cout << "Unfortunately.";
    return 0;
}
