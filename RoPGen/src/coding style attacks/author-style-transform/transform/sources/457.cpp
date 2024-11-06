#include <iostream>
using namespace std;
int main() {
    int sum=0;
    double n,a,b;
    double t,T;
    cin>>n>>a>>b;
    t=(n*a-600)/(b-a);
    T=t;
    sum=T*10;
    if(sum%10>4){
        sum=t+1;
    }
    else{
        sum=t;
    }
    cout<<sum<<endl;
    return 0;
}
