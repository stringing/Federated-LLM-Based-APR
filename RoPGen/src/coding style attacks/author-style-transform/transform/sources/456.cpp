#include <bits/stdc++.h>
#include <vector>
using namespace std;
double summer[1005],num[1005];
struct limk
{
    int kind;
    int unit;
    int day;
};
vector <limk> v;
bool cmp(limk a,limk b)
{
    if(a.kind!=b.kind)
    {
        double x=summer[a.kind]/num[a.kind];
        double y=summer[b.kind]/num[b.kind];
        if(x!=y)
        {
            return x>y;
        }
    }
    else
    {
        if(a.unit!=b.unit)
        {
            return a.unit>b.unit;
        }
        else
        {
            return a.day<b.day;
        }
    }
}
int main()
{
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        limk a;
        int g;
        cin>>a.kind>>a.unit>>g;
        summer[a.kind]+=a.unit*g;
        num[a.kind]+=g;
        for(int i=1;i<=g;i++)
        {
            a.day=k;
            v.push_back(a);
            k++;
        }
    }
    sort(v.begin(),v.end(),cmp);
    long long ans=0;
    for(int i=0;i<=v.size()-1;i++)
    {
        ans+=abs(v[i].day-i);
    }
    cout<<ans<<endl;
    return 0;
}

