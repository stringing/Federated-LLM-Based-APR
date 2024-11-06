#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> G[1005];
int main(){
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n - 1; j++){
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = 0;
        for(int j = 1; j <= n; j++){
            bool flag = true;
            if(G[j].size() == 0){
                continue;
            }
            for(int k = 0; k < G[j].size(); k++){
                int t = G[j][k];
                if(G[j].size() < G[t].size()){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
