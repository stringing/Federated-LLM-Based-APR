#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    int b=0,c=0,e,d,j=0;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i]!=' '){
            b++;
        }
        if(a[i]==' '){
            if(b>c){
            c=b;
            d=i-1;
            while(a[d]!=' '){
                d--;
            }   
        }
        b=0;
        }
    }
     for(int i=0;i<a.size();i++){
         if(a[i]!=' '){
            j++;
        }else{
             if(j>c){
                 c=j;
                 d=i-1;
                while(a[d]!=' '){
                  d--;
               }
             }
             j=0;
         }
     }
    e=d+1;
    while(a[e]!=' '){
        cout<<a[e];
        e++;
    }
}
