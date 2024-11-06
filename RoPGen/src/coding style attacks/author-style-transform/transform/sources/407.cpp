#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a,b[100001];
int sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main()
{
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
        sum(b[i]);  
    }
    sort(b,b+a);
    for(int i=0;i<a;i++)
    {
        cout<<b[i]<<" ";
    }
    
}
