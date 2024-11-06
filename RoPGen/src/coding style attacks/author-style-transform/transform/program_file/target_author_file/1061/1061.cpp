#include<bits/stdc++.h>
using namespace std;
string o;
char getchar(string pass)
{
    int a;
    for(int i=3;i<8;++i)
    {
        a=a+((int)(pass[i]-'0'))*pow(2,7-i);
    }
    return 'A'+a;
}
bool fanyi(string s)
{
    if(s[0]=='0')   return 0;
    if(s[0]=='1'&&s[1]=='1'&&s[2]=='1')
    {
        o+=' ';
        return 0;
    }
    if(s[0]=='1'&&s[1]=='0'&&s[2]=='1')
    {
        o+=getchar(s);
        return 0;
    }
    return 1;
}
int main()
{
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    string s;
    cin>>s;
    if(s.size()%8!=0)
    {
        cout<<"Error";
        return 0;
    }
    for(int i=0;i<s.size();i+=8)
    {
        string str;
        for(int j=0;j<8;++j)
        {
            str.push_back(s[i+j]);
        }
        if(fanyi(str))
        {
            cout<<"Error";
            return 0;
        }
    }
    cout<<o;
}
