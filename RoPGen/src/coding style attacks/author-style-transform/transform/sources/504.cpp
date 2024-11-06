#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int max,num,ma,nu,p,mp;
    max=0;
    num=0;
    num+=1;
    nu=0;
    for(int i = 1;i <s.size();i++){
        if(s[i]!= ' '){
           
            num++;
        }else if(s[i]==' '){
            if(num >max){
                max = num;
                ma=nu;
                p=i-1;
                mp=p;
                i+=1;
                num=0;
                p=0;
                nu=0;
                nu=i;
            }
        }
        
    }
    cout << s.substr(ma,mp);
    return 0;
}
