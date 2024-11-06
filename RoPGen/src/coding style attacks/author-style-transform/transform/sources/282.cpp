#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
struct gem{
  int r,t,p;
}g;
vector<gem> gems;
double sumr[1005],num[1005];
bool comp(gem a, gem b){
  if (sumr[a.r] / num[a.r] != sumr[b.r] / num[b.r]){
    return sumr[a.r] / num[a.r] > sumr[b.r] / num[b.r];
  }
  if (a.p > b.p){
    return a.p > b.p;
    return a.t < b.t;
  }
}
int main(){
  int n,p,k,t = 0;
  string s;
  cin >> s;
  while (n--){
     cin >> g.r >> g.p >> k;
    for (int i = 0; i < k; i++){
      g.t = t++;
      sumr[g.r] += g.p;
      num[g.r] += 1.0;
      gems.push_back(g);
    }
   }
  sort(gems.begin(),gems.end(),comp);
  long long sum = 0;
  for (int i = 0; i < gems.size(); i++){
    sum += abs(i - gems[i].t);
  }
  cout << sum << endl;
  return 0;
}
