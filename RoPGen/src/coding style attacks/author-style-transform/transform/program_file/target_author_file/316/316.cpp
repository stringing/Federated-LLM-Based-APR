#include <bits/stdc++.h>
using namespace std;
string cay="can you ",coy="could you ",ica="I can ",ico="I could ";
string m="me ",ii="i ",y="you ";
string a;
void ct(){
    for(int i=0;i<a.size();i++){
        if(a[i]>='A'&&a[i]<='Z'){
            a[i]=a[i]-'A'+'a';
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        getline(cin,a);
        ct();
        while(a.find(cay)<a.size()&&a.find(cay)>=0){
            a.insert(a.find(cay),ica);
            a.erase(a.find(cay),8);
        }
        while(a.find(coy)<a.size()&&a.find(coy)>=0){
            a.insert(a.find(coy),ico);
            a.erase(a.find(coy),10);
        }
        while(a.find(m)<a.size()&&a.find(m)>=0){
            a.insert(a.find(m),y);
            a.erase(a.find(m),3);
        }
        while(a.find(ii)<a.size()&&a.find(ii)>=0){
            a.insert(a.find(ii),y);
            a.erase(a.find(ii),2);
        }
        while(a.find("?")<a.size()&&a.find("?")>=0){
            a.replace(a.find("?"),1,"!");
        }
        cout<<a<<endl;
    }
}
