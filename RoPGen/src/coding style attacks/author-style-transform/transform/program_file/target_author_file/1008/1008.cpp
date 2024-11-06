#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
    int a,b,n,d;
    double c;
    cin>>n>>a>>b;
    c=(n*a-600)/(b-a);
    d=c;
    if(d!=c){
        d++;
    }
    cout<<d<<endl;
    return 0;
}
