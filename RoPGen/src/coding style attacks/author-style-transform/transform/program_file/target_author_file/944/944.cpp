#include<bits/stdc++.h>
using namespace std;
struct stru{
    int r, p, id0, id1, pc;
    double pj;
};
struct stru2{
    double pj0;
    int dr, s_p, s_k;
};
bool cmp(stru a, stru b){
    if(a.pj>b.pj)return 1;
    else if(a.pj == b.pj){
        if(a.p > b.p)
            return 1;
        else if(a.p == b.p){
            if(a.pc < b.pc)
                return 1;
            else
                return 0;
        }
        else return 0;  
    }
    else return 0;
}
vector<stru2> d;
int main(){
    vector<stru> v; 
    int n;
    cin >> n;
    int index = 1, r0, p0, x;
    
    for(int i = 1; i <= n; i++){
        cin >> r0 >> p0 >> x;
        int flag = 1, len = d.size(), m;
        for(m = 0; m < len; m++){
            if(d[m].dr == r0){
                flag = 0;
                d[m].s_p += p0*x;
                d[m].s_k += x;
            }
        }
        if(flag){
            stru2 tmp;
            tmp.dr = r0;
            tmp.s_k = x;
            tmp.s_p = p0*x; 
            d.push_back(tmp);
        }
        for(int j = 1; j <= x; j++){
            stru ts;
            ts.id0 = index++;
            ts.p = p0;
            ts.r = r0;
            ts.pc = i;
            v.push_back(ts);
        }
    }
    int len_d = d.size();
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < len_d; j++)
            if(v[i].r == d[j].dr){
                v[i].pj = 1.0*d[j].s_p/d[j].s_k;
                break;
            }
    
    }
    sort(v.begin(), v.end(), cmp);
    int summ = 0;
    for(int i = 0; i < v.size(); i++){
        v[i].id1 = i+1; 
        summ += abs(v[i].id0-v[i].id1);
    
    }
    cout << summ;
    return 0;
}
