#include<bits/stdc++.h>
using namespace std;
struct stru{
    int ti;
    string name;
};
int main(){
    string s;
    vector<stru> ve;
    int timm, summ = 0;
    cin >> timm;
    char ch;
    ch = getchar();
    while(cin >> s){
        int tmp = 0;
        if(s != "tingtingting")
            cin >> tmp; 
        stru t;
        t.name = s;
        t.ti = tmp;
        ve.push_back(t);
    }



    for(int i = 0; i < ve.size(); i++){
    
        if(ve[i].name != "tingtingting" && ve[i+1].name != "tingtingting" && ve[i].name != "kaomianjin")
            summ += ve[i].ti;
        if(summ > timm){
            cout<<"Unfortunately.";
            return 0;
        }
        if(ve[i].name == "kaomianjin"){
            if(ve[i+1].name != "tingtingting"){
                cout<<"Congratulations!";
                return 0;
            }
            else{
                cout << "Hahaha.";
                return 0;
            }
        }
    }
    return 0;
}

