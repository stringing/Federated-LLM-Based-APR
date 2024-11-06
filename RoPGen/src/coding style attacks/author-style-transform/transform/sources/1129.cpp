#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    getchar();
    while(n){
        string s;
        getline(cin,s);
    }
    string f[100] = {};
    int x = 0;
    for(int i = 0;i < f.size();i++){
        if(f[i] >= "A"&&f[i] <= "Z"&&f[i] != "I"){
            f[i] += 32;
        }
        if(f[i] == "?"){
            f[i] = "!";
        }
        if (f[i] != " "){
            f[x] += f[i];
        }else{
            x++;
        }
    }
    for(int i = 0;i <= x;i++){
        if(f[i] == "can"&&f[i + 1] == "you"){
            cout << "I can" << f[i] << " ";
        }
        if(f[i] == "could"&&f[i + 1] == "you"){
            cout << "I could" << f[i] << " ";
        }
        if(f[i] == "I"||f[i] == "me"){
            cout << "you" <<" ";
        }
    }
}
