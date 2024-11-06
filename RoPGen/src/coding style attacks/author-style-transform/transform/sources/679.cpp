#include <iostream>
#include<string>
using namespace std;
string sum,s;
int n;
int main(){
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    while(cin>>s){
        n=s.size();
        sum+=s;
    }
    cout<<n<<" ";
    int asns=sum[0]-'0',suma=0;
    for(int i=0;i<sum.size();i++){
        if(asns!=sum[i]-'0'){
            asns=sum[i]-'0';
            cout<<suma<<" ";
            suma=1;
        }else{
            suma++;
        }
        if(i==sum.size()-1){
            cout<<suma;
        }
    }
    return 0;
}
