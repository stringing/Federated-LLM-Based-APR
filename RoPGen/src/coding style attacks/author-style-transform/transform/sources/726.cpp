#include <iostream>
#include <string>
using namespace std;
int main(){
    string c;
    string z,max="";
    getline(cin,c);
    for(int i=0;i<c.size();i++){
        if(c[i]!=' '){
            z=z+c[i];
        }else{
            if(z.size()>max.size()){
                max=z;
            }
            z="";
        }    
    }
    cout<<max<< endl;
    return 0;
}
