#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;string a;
    for (int i = 0;i < n;i++){
        getline(cin,a);
        
        for (int j = 0;j < a.size();j++){
            if (a[j] < 95&&a[j]>64&&a[j]!= 73){
                a[j]+=32;
            }
        }
        if (a.find("I") != string::npos){
            a.replace(a.find("I"),1,"you");
        }
        if (a.find("me") != string::npos){
            a.replace(a.find("me"),2,"you");
        }
        if (a.find("can you") != string::npos){
            a.replace(a.find("can you"),7,"I can");
        }
        if (a.find("sould you") != string::npos){
            a.replace(a.find("sould you"),9,"I sould");
        }
        if (a.find("?") != string::npos){
            a.replace(a.find("?"),1,"!");
        }
        
        cout << a << endl;
    }
}
