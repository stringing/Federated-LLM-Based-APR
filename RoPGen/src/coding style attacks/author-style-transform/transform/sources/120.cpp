#include<bits/stdc++.h>
using namespace std;


bool pd(int x,int y){
    int sumx = 0,sumy = 0;
    for(int i = 1;i < 5;i++){
        sumx += x % 10;
        x /= 10;
    }
    for(int i = 1;i < 5;i++){
        sumy += y % 10;
        y /= 10;
    }
   
   
   
   
   
    
    
      return sumx < sumy || sumx == sumy && x < y;
}
    
int a[101];
    
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n,pd);
    for(int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
