#include <iostream>
#include <algorithm>
using namespace std;
int n, b;
int minx = 100000000;
int comb[30];
int dfs(int x, int sum) { 
    if (sum >= b) {
         return min(sum - b, minx);
    }
    if(x > n){
        return 0;
    }
    int i = x;
    minx = sum;
    dfs(x + 1, sum + comb[i]);
    dfs(x + 1, sum);
}
int main(){
    freopen("shelf.in", "r", stdin);
    freopen("shelf.out", "w", stdout);
    cin >> n >> b;
    for(int i = 1; i <= n; i++){
        cin >> comb[i];
    }
    cout << dfs(1, 0) << endl;
    return 0;
}
