#include<iostream>

using namespace std;
int main()
{
    
    double n,a,b,d;
    int e,c;
    cin>>n>>a>>b;
    n=n*a-600;
    a=n/(b-a);
    cout<<a<<endl;
    e=a;
    e=e*10;
    cout<<e<<endl;
    c=a*10;
    cout<<c<<endl;
    d=c-e;
    e=e/10;
    if(d>=5)
    {
        e++;
    }
    else
    {
        a+=0;
    }
    cout<<e<<endl;
    return 0;
} 
    

