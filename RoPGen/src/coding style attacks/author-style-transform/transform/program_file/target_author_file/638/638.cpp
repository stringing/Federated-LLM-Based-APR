#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    string s;
    int t,allt,sum=0;
    cout<<allt;
    allt*=60;
    while(cin>>s)
    {
        if(s=="tingtingting")
        {
            v.pop_back();
            sum=v[v.size()-1];
        }else if(s=="kaomianjin")
        {
           cin>>t;
            if(cin>>s&&s=="tingtingting")
            {
                cout<<"Hahaha."<<endl;
                return 0;
            }
            cout<<"Congratulations!"<<endl;
            return 0;
        }
        else
        {
            cin>>t;
            sum+=t;
            if(sum>=allt)
            {
                break;
            }
            v.push_back(sum);
        }
    }
    cout<<"Unfortunately.";
    return 0;
}
