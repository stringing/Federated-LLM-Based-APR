#include <iostream>
using namespace std;   
int main() {
    int n,a,b,ms;
        
    double m;
    cin>>n>>a>>b;
    m=(n*a-600)/(b-a);
    ms=int(m);
    if(ms!=m){
        cout<<ms+1;
    }else{
       cout<<ms;
    }
 
    return 0;
}

