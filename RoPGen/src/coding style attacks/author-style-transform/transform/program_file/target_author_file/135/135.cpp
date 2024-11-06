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
    return sumr[a.r] / num[a.r] < sumr[b.r] / num[b.r];
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
      
    }
   }
}
