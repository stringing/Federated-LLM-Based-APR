#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    n*=60;
    do
    {
        string a;
        cin>>a;
        if(a=="kaomianjin")
        {
            cin>>m;
            cin>>a;
            if(a=="tingtingting")
            {
                cout<<"Hahaha.";
                return 0;
            }
            cout<<"Congratulations!";
            return 0;
        }
        if(a=="tingtingting")
        {
            break;
        }
        else
        {
            cin>>m;
            n-=m;
        }
    }while(n>0);
    cout<<"Unfortunately.";
    return 0;
}
