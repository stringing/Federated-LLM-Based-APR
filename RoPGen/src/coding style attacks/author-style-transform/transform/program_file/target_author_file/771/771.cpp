#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct gem{
  int r,p,t;
}g;
vector<gem>vgems;
double sumr[100005],num[100005];
bool cmp(gem a,gem b){
  if(sumr[a.r]/num[a.r]!=sumr[b.r]/num[b.r]){
    return sumr[a.r]/num[a.r]>sumr[b.r]/num[b.r];
  }
  if(a.p!=b.p){
    return a.p>b.p;
  } 
  return a.t<b.t;
  
}
int main(){
  long long n,k,sum,b;
  cin>>n;

  while(n--){
    cin>>g.r>>g.p>>k;
    for(int i = 0;i<k;i++){
      g.t=b++;
      sumr[g.r]+=g.p;
      num[g.r]+=1.0;
      vgems.push_back(g);
    }
    
    
  }
  sort(vgems.begin(),vgems.end());
  for(int i = 0;i<vgems.size();i++){
    sum+=abs(i-vgems[i].t);
  }
  cout<<sum<<endl;
  return 0;
}
