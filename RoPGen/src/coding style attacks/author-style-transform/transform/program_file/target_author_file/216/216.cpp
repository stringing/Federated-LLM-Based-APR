#include<bits/stdc++.h>
using namespace std;
struct baoshi{
    int r,p,t;
};
baoshi g;
double sumr[1000+10],num[1000+10];
bool cmp(baoshi a,baoshi b){
    if(sumr[a.r]/num[a.r]!=sumr[b.r]/num[b.r]){
        return sumr[a.r]/num[a.r]<sumr[b.r]/num[b.r];
    }
    if(a.p!=b.p)return a.p>b.p;
    return a.t<b.t;
}
int main(){
    vector<baoshi> gems;
    int n,p,k,t=0;
    string s;
    cin>>n;
    while(n--){
        cin>>g.r>>g.p>>k;
        for(int i=0;i<k;i++){
            g.t=t++;
            sumr[g.r]+=g.p;
            num[g.r]+=1.0;
            gems.push_back(g);
        }
    }
    sort(gems.begin(),gems.end());
    long long sum=0;
    for(int i=0;i<gems.size();i++){
        sum+=abs(gems[i].p,gems[i].r);
    }
    cout<<sum<<endl;
}
