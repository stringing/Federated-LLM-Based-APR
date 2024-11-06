#include<bits/stdc++.h>
using namespace std;
struct mnb{
    int r,t,p;
}m;
vector<mnb> mnbs;
double i0[1005],ii0[1005];
bool mnx(mnb a,mnb b){
    if(i0[a.r]/ii0[a.r] != i0[b.r]/ii0[b.r]){
        return i0[a.r]/ii0[a.r] < i0[b.r]/ii0[b.r];
    }else if(a.p!=b.p){
        return a.p>b.p;
    }else{
        return a.t<b.t;
    }
}
int main(){
    int n,k,l,o=0;
    string s;
    cin>>n;
    while(n--){
        cin>>m.r>>m.p>>k;
        for(int i=0;i<k;i++){
            m.t=o++;
            i0[m.r]+=m.p;
            ii0[m.r]+=1.0;
            mnbs.push_back(m);
        }
    }
    sort(mnbs,mnbs+mnbs.size(),mnx);
    long long io;
    for(int i=0;i<mnbs.size();i++){
        io+=abs(i-m[i].r);
    }
    cout<<io<<endl;
    return 0;
}
