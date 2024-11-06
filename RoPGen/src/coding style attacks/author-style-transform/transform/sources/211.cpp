#include<iostream>
#include<string>
using namespace std;
int main(){
    string V;
    int a,n,in,IN;
    getline(cin,V);
    for(int i =0;i<V.size();i++){
        if(V[i]=' '){
            n=0;
            in=i+1;
            continue;
        }else{
            n+=1;
        }
        if(n>a){
            a=n;
            IN=in;
            
        }
    }
     if(n>a){
            a=n;
            IN=in;
            
        }
    for(int i=0;i<a;i++){
        cout << V[IN+i];
    }
   return 0;
}
