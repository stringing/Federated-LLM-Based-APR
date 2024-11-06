#include<iostream>
using namespace std;
int main(){
    int a,b,n,k;
    double c;
    cin>>n>>a>>b;
    k=a*n;
    double k_double=double(k);
    double a_double=double(a);
    double b_double=double(b);
    c=(k-600)/(b-a);
    int c_int=int(c);
    if(c_int!=c){
        c++;
    }
    cout<<c<<endl;
    return 0;
}
