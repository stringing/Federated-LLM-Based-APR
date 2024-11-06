#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct gem
{
    int r,t,p;
};
vector<gem> gems;
double sumr[10005],num[10005];
bool comp(gem a,gem b)
{
    if(sumr[a.r]/num[a.r]!=sumr[b.r]/num[b.r])
        return sumr[a.r]/num[a.r]<sumr[b.r]/num[b.r];
    if(a.p!=b.p)
        return a.p>b.p;
    return a.t<b.t;
}
int main()
{
    int n,p,k,t=0;
    cin>>n;
    string s;
    
    while(n--)
    {
        gem g;
        cin>>g.r>>g.p>>k;
        for(int i=0;i<k;i++)
        {
            g.t=t++;           
            num[g.r]+=1.0;     
            sumr[g.r]+=g.p;    
            gems.push_back(g);
        }
    }
    int l=gems.size();
    sort(gems.begin(),gems.begin()+gems.size(),comp);
    long long sum=0;   
    for(int i=0;i<gems.size();i++)
    {
        sum+=abs(gems[i].t-i-1);
    }
    cout<<sum;
    return 0;
}
