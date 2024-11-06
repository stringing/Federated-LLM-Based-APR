#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
const int maxn = 1006 ; 
const int minn = -999999999;
int maze[maxn][maxn];
int dp1[maxn][maxn] , dp2[maxn][maxn] , dp3[maxn][maxn] , dp4[maxn][maxn] ;
int n, m , x ,y , v ,c ;
int dp_1 (int tx , int ty) {
     dp1[tx][ty] = v ;
    if (tx == n && ty == 0 ) {
        return dp1[tx][ty];
    } 
    for (int i = tx ; i >= 0 ; i--) {
        for (int j = ty  ; j >= 0 ; j--) {
            if(i == tx && j == ty ) continue;
            if (i == tx) dp1[i][j] = dp1[i][j+1] + maze[i][j] ;
            if (j == ty) dp1[i+1][j] + maze[i][j] ;
            dp1[i][j] = max(dp1[i+1][j] , dp1[i][j+1]) + maze[i][j] ;   
            if (dp1[i][j] <= 0) dp1[i][j] = minn;
            if (dp1[i][j] > c) dp1[i][j] = c ;
        }
    }
    if (dp1[0][0] <= 0) return -1 ;
    else return dp1[0][0];
}
int dp_2 (int tx , int ty) {
    dp2[tx][ty] = v ;
    if (tx == n && ty == 0 ) {
         return dp2[tx][ty] ;
    } 
    for (int i = tx ; i >= 0 ; i--) {
        for (int j = ty + 1; j < m ; j++) {
            if (i == tx && j == ty) continue ;
            if (i == tx ) dp2[i][j] = dp2[i][j-1] + maze[i][j] ;
            if (j == ty ) dp2[i][j] = dp2[i+1][j] ;
            dp2[i][j] = max(dp2[i+1][j] , dp2[i][j-1]) + maze[i][j] ;
            if (dp2[i][j] <= 0) dp2[i][j] = minn;
            if (dp2[i][j] > c) dp2[i][j] = c ;
        }
    }
    if (dp2[0][m-1] <= 0) return -1;
    else return dp2[0][m-1] ;
}
int dp_3(int tx, int ty) {
     dp3[tx][ty] = v ;
    if (tx == n && ty == 0 ) {
       return dp3[tx][ty] ;
    } 
    for (int i = tx ; i < n ; i++) {
        for (int j = ty - 1 ; j >= 0 ; j--) {
            if (i == tx && j == ty) continue ;
            if (i == tx ) dp3[i][j] = dp3[i][j+1] + maze[i][j] ;
            if (j == ty ) dp3[i][j] = dp3[i-1][j] ;
            dp3[i][j] = max(dp3[i-1][j] , dp3[i][j+1]) + maze[i][j] ;
            if (dp3[i][j] <= 0) dp3[i][j] = minn;
            if (dp3[i][j] > c) dp3[i][j] = c ;
        }
    }
    if (dp3[n-1][0]= 0) return -1 ;
    else return dp3[n-1][0] ;
}
int dp_4 (int tx  , int ty ) {
   dp4[tx][ty] = v ;
   if (tx == n && ty == 0 ) {
        return dp4[tx][ty] ;
    } 
    for (int i = tx ; i < n ; i++) {
        for (int j = ty+ 1 ; j < m ; j++) {
            if (i == tx && j == ty) continue ;
            if (i == tx ) dp4[i][j] = dp4[i][j-1] + maze[i][j] ;
            if (j == ty ) dp4[i][j] = dp4[i-1][j] ;
            dp4[i][j] = max(dp4[i-1][j] , dp4[i][j-1]) + maze[i][j] ;
            if (dp4[i][j] <= 0) dp4[i][j] = minn;
            if (dp4[i][j] > c) dp4[i][j] = c ;
        }
    }
    if (dp4[n-1][m-1] <= 0) return -1 ;
    else return dp4[n-1][m-1] ;
}
int main () {
    iostream::sync_with_stdio(false) ; 
    freopen("escape.in" , "r" , stdin) ;  
    freopen("escape.out" , "w" , stdout) ;
    cin >> n >> m >> x >> y >>v >> c ;
   for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++) {
            cin >> maze[i][j];
        }
    }
    x -= 1 ;
    y -= 1 ;
    int a1 = dp_1(x,y);int a2 = dp_2(x,y); int a3 = dp_3(x,y);int a4 = dp_4(x,y);
    int a = max ( max( max(a1,a2) , max(a2,a3)) , max(a3,a4) );
    cout << a  << endl;
    return 0 ;
} 
