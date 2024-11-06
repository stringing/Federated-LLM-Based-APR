#include <iostream>
#include <string>
using namespace std;
int main(){
    string b[100];
    int a;
    cin >> a;
    for(int i = 0; i < a; i++){
        getline(cin,b[i]);   
    }
    for(int i = 0; i < a; i++){
        while(b[i].find("can you") != string::npos){
            b[i].replace(b[i].find("can you"),5,"I can");
        }
        while(b[i].find("could you") != string::npos){
            b[i].replace(b[i].find("could you"),7,"I could");
        }
        while(b[i].find('I') != string::npos || b[i].find("me") != string::npos){
            b[i].replace(b[i].find("could you"),3,"you");    
        }
        while(b[i].find('?') != string::npos){
            b[i].replace(b[i].find('?'),1,"!");    
        }
    }
    for(int i = 0; i < a; i++){
        cout << b[i] <<endl;
    }
    return 0;
}
