#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    n*=60;
    string a,b;
    while(cin>>a)
    {
        if(a=="kaomianjin")
        {
            cin>>m;
            cin>>b;
            if(b=="tingtingting")
            {
                cout<<"Hahaha.";
                return 0;
            }
            cout<<"Congratulations!";
            return 0;
        }
        cin>>b;
        if(b=="tingtingting")
        {
            continue;
        }
        else
        {
            cin>>m;
            n-=m;
            continue;
        }
        if(n<0)
        {
            cout<<"Unfortunately.";
            return 0;
        }
    };
    return 0;
}
