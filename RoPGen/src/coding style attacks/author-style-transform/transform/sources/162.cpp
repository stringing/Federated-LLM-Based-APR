#include <bits/stdc++.h>
using namespace std;
struct gem{
    int r, t, p;
}g;
vector<gem> gems;
double sumr[1005], num[1005];
bool comp(gem a, gem b) {
    if (sumr[a.r] / num[a.r] != sumr[b.r] / num[b.r]) 
        return sumr[a.r] / num[a.r] > sumr[b.r] / num[b.r];
    if (a.p != b.p) 
        return a.p > b.p;
    return a.t < b.t;
}
int main(){
    int n, p, k, t;
    string s;
    cin >> n;
    while(n--){
        cin >> g.r >> g.p >> k;
        for(int i = 0; i < k; i++){
            g.t = t++;
            sumr[g.r] += g.p;
            num[g.r] += 1.0;
            gems.push_back(g);
        }
    }
    for (int i = 0; i < gems.size(); i++) {
        num += abs(i - gems[i].t);
    }
    cout << num << endl;
    return 0;
}
