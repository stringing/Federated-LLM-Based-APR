#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,max="wu";
    int ix=0;
    getline(cin, a);
    for(int i=0;i<a.size();i++){
        if(a[i]==' '){
            int ixt=i-ix;
            if(max=="wu"){
                
                max=a.substr(ix,i-ix);
            }else if(ixt>max.size()){
                    max=a.substr(ix,i-ix);
                }
           
            ix=i+1;
        } 
        int ixt=i-ix;
        if(i==a.size()-1){
                if(ixt>max.size()){
                    max=a.substr(ix,i-ix+1);
                }
            }
    }
    cout<<max;
    return 0;
}
