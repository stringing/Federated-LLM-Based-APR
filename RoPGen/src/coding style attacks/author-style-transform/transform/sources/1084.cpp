#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
vector<int> G[maxn];
int main () {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int n,t,x,y;
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        if (a == 0) { 
         G[x].push_back(y);
        } else {
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << i << ":"; 
        for(int j=G[i].size()-1;j>=0;j--){
            cout<<" "<<G[i][j];
        }
        cout << endl;
    }
    return 0;
}

