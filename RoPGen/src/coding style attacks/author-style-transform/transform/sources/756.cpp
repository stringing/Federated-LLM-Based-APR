#include<bits/stdc++.h>
using namespace std;
string d,e[10005];
int main(){
    int a,c,f=0;
    cin>>a;
    for(int b=1;b<=a;b++){
        cin>>c;
        if(c==1){
            cin>>d;
            f++;
            d=e[f];
        }else if(c==2){
           if(f){
              cout<<e[1]<<endl;
              for(int g=2;g<=f;g++){
                  e[g-1]=e[g];
              }
              f--;
           }else{
               cout<<0<<endl;
           }
        }
    }
    return 0;
}
