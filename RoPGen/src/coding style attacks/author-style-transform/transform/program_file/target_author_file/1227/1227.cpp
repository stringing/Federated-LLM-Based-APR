#include <iostream>
#include <algorithm>
using namespace std;
int sum(int x) {
    int s = 0;
    while(x) {
      s+=x%10;
      x/=10;
    }
    return s;
  }
  
void bool cmp(int a, int b){
  if (sum(a)!=sum(b)) {
    return sum(a) < sum(b);
  }
  return a > b;
}
int main(){
  int a;
  cin>>a;
  string num[105];
    for (int i = 0; i < a; i++){
      cin>>num[i];
    }
  sort(num,num+a,cmp);
  for (int j = 0; j < a; j++ ){
    cout<<num[j]<<" ";
  }
    
  return 0;
}
