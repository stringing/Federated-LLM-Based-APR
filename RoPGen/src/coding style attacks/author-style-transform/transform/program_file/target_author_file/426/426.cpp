#include<bits/stdc++.h>
using namespace std;
string o;
long long sum=0;
vector<int> ret;
map<string,string> mp;
char getchar(string pass)
{
    int a=0;
    for(int i=3;i<8;++i)
    {
        a=a+((int)(pass[i]-'0'))*pow(2,7-i);
    }
    if(a>=26)
    {
        return 'e';
    }
    return 'A'+a;
}
int getint(string pass)
{
    int a=0;
    for(int i=1;i<8;++i)
    {
        a+=((int)(pass[i]-'0'))*pow(2,7-i);
    }
    return a;
}
int fanyi(string s)
{
    for(int i=0;i<8;++i)
    {
        if(s[i]!='0'&&s[i]!='1')    return 1;
    }
    if(s[0]=='0')
    {
        sum+=getint(s);
        sum/=2;
        return 2;
    }
    if(s[0]=='1'&&s[1]=='1'&&s[2]=='1')
    {
        o+=' ';
        return 0;
    }
    if(s[0]=='1'&&s[1]=='0'&&s[2]=='1')
    {
        char cha=getchar(s);
        if(cha=='e')
        {
            return 1;
        }
        o+=cha;
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
        string str="";
        for(int j=0;j<8;++j)
        {
            str.push_back(s[i+j]);
        }
        int retu=fanyi(str);
        if(retu==1)
        {
            cout<<"Error";
            return 0;
        }else
        {
            ret.push_back(retu);
        }
    }
    int num_cnt=0;
    for(int i=0;i<=ret.size()-1;++i)
    {
        if(ret[i]==2&&ret[i-1]!=2&&ret[i+1]!=2)
        {
            cout<<"Error";
            return 0;
        }
        if(ret[i]==2)
        {
            ++num_cnt;
        }
    }
    if(num_cnt%2==1)
    {
        cout<<"Error";
        return 0;
    }
    cout<<o;
    if(sum!=0)
    {
        cout<<sum;
    }
}
