#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string b[100];
    int a;
    cin >> a;
    getchar();
    for(int i = 0; i < a; i++){
        getline(cin,b[i]);   
    }
    bool c = true;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b[i].size(); j++){
            if (('A' <= b[i][j] && b[i][j] <= 'Z') && b[i][j] != 'I'){
                    b[i][j] = (b[i][j] - 'A' + 'a');
                }
        }
    }
    for(int i = 0; i < a; i++){
        while(b[i].find("can you") != string::npos){
            b[i].replace(b[i].find("can you"),7,"I can");
            c = false;
        }
        while(b[i].find("could you") != string::npos){
            b[i].replace(b[i].find("could you"),9,"I could");
            c = false;
        }
        while(b[i].find('I') != string::npos && c){
            b[i].replace(b[i].find("I"),1,"you");    
        }
        while(b[i].find("me") != string::npos){
            b[i].replace(b[i].find("me"),2,"you");    
        }
        while(b[i].find('?') != string::npos){
            b[i].replace(b[i].find('?'),1,"!");    
        }
    }
    for(int i = 0; i < a; i++){
        cout << b[i] << endl;
    }
    return 0;
}
