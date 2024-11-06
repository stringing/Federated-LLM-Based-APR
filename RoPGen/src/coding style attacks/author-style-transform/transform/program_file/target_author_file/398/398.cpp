#include <iostream>
#include <algorithm>
using namespace std;
int px(int a,int b)
{
    int x=0,y=0,a1=a,b1=b;
        while(a1>0){
            x+=a1%10;
            a1/=10;
        }
        while(b1>0){
            y+=b1%10;
            b1/=10;
        }
    if(x<y)
    {
        return x<y;
    }
    else if(x==y)
    {
            return a<b;
    }
}
int main() {
    int n;
    cin>>n;
    int k[105];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    sort(k,k+n,px);
    for(int i=0;i<n;i++)
    {
        cout<<k[i]<<" ";
    }
    return 0;
}
