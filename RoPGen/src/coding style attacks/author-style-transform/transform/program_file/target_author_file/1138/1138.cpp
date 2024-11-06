#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
double num[1005],sumer[1005];
struct gem{
    int r,p,t;
}g;
vector<gem> gems;
bool cmp(gem a,gem b){
    if(sumer[a.r] / num[a.r] != sumer[b.r] / num[b.r]){
        return sumer[a.r] / num[a.r] > sumer[b.r] / num[b.r];
    }
    if(a.p != b.p){
        return a.p > b.p;
    }
    return a.t < b.t;
}
int main(){
    int n,p,k,t = 0;
    string s;
    cin >> n;
    while(n--){
        cin >> g.r >> g.p >> k;
        for(int i = 0;i < k;i++){
            g.t = t++;
            sumer[g.r] += g.p;
            num[g.r] += 1.0;
            gems.push_back(g);
        }
    }
    sort(gem.begin(),gem.end(),cmp);
    long long sum = 0;
    for(int i = 0;i < gems.size();i++){
        sum += abs(gems[i] - g[i]);
    }
    cout << sum;
    return 0;
}
