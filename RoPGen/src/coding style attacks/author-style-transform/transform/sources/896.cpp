#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int a[505][2000] = {1};
int len[505] = {1};
int main() {
    freopen("factorial.in", "r", stdin);
    freopen("factorial.out", "w", stdout);
  int y;
  cin >> y;
   for(int n = 0; n < y; n ++) {
    for(int x = 1; x <= n; x++ ) {
      for (int i = 0; i < len[n]; i++) {
    a[n][i] *= x;
}
 for (int i = 0; i < len[n]; i++) {
    a[n][i + 1] += a[n][i] / 10;
    a[n][i] %= 10;
 }
 while (a[n][len[n]]) {
    a[n][len[n] + 1] += a[n][len[n]] / 10;
    a[n][len[n]] %= 10;
    len[n]++;
   }
 }
   len[n] = max(len[n], len[n-1]);
for (int i = 0; i < len[n]; i++) {
    a[n][i] += a[n - 1][i];
}
for (int i = 0; i < len[n]; i++) {
    a[n][i + 1] += a[n][i] / 10;
    a[n][i] %= 10;
}
while (a[n][len[n]]) {
    a[n][len[n] + 1] += a[n][len[n]] / 10;
    a[n][len[n]] %= 10;
    len[n]++;
}  
   }
  for(int i = len[y - 1] - 1; i >= 0; i--) {
    cout << a[y - 1][i];
  }  
  return 0;
}
