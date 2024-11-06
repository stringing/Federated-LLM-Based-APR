#include<bits/stdc++.h>
using namespace std;
int n;
bool row[15],x1[30],x2[30];
int value[15][15];
int ans = 0;
 bool check(int i,int c) {
   return !row[i] && !x1[i + c] && !x2[i - c + n] && value[i][c] == 1;
 }
void dfs(int c,int op) {
  if(op == 3) {
    ans++;
    return;
  } 
  if(c == n) {
    memset(row,0,sizeof(row));
    memset(x1,0,sizeof(x1));
    memset(x2,0,sizeof(x2));
    dfs(0,op + 1);
    return;
  }
  for(int i = 0; i < n; i++) {
    if(check(i,c))  {
      row[i] = x1[i + c] = x2[i - c + n] = true;
      value[i][c] = 0;
      dfs(c + 1,op);
        value[i][c] = 1;      
      row[i] = x1[i + c] = x2[i - c + n] = false;
    }
  }
}
int main() {
  freopen("queen.in", "r", stdin);
  freopen("queen.out", "w", stdout);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> value[i][j];
    }
  }
    dfs(0,1);
  cout << ans << endl;
    return 0;    
}
