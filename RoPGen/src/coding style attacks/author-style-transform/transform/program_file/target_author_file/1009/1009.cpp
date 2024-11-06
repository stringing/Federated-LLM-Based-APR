#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
    int a,b,n,d;
    double c;
    cin>>n>>a>>b;
    c=(n*a-600)/(b-a);
    if((int)c<c)
    {
        c=(int)c;
    }
    cout<<c+1<<endl;
    return 0;
}
