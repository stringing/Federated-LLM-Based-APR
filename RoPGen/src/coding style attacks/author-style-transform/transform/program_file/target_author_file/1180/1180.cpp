#include <bits/stdc++.h>
using namespace std;
long long a[100005],sum=0;
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }sort(a+1,a+1+n);
  long long floor=0;
  for(int i=1;i<=n;i++)
  {
    if(a[i]>floor)sum+=(a[i]-floor)*5+5;
    
    if(a[i]==floor)sum+=2;
    floor=a[i];
  }sum+=floor*4;
  cout<<sum;
  return 0;
}
