#include <iostream>
#include <algorithm>
bool cmp1(int x,int y){
    return x<y;
}
using namespace std;
int main(){
  int n,a[10000],max=a[0];
  cin>>n; 
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n,cmp1);
  for(int j=0;j<n;j++){
    cout<<a[j]<<" ";
  }
  
return 0;
}
