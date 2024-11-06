#include<iostream>
using namespace std;
int main(){
    int a,b,n,k;
    double c;
    cin>>n>>a>>b;
    k=a*n;
    c=(k-600)/(b-a);
    int c_int=int(c);
    if(c_int!=c){
        c++;
    }
    cout<<c<<endl;
    return 0;
}
