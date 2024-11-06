#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int du = 0;
    int F_du = 0;
    int F = 0;
};
int main(){
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> G[n+1];
        int G_size[n+1] = {0};
        Node g[n+1];
        for(int i = 0;i < n - 1;i++){
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            g[x].du += 1;
            g[y].F_du += 1;
            g[y].F = x;
            G_size[x] += 1;
        }
        int p = 0;
        for(int i = 1;i <= n;i++){
            bool P = 1;
            for(int j = 1;j <= G_size[i];j++){
                if(g[G[i][j]].du >= g[i].du){
                    P = 0;
                }
            }
            if(g[g[i].F].du >= g[i].du){
                P = 0;
            }
            p += P;
        }
        cout << p << endl;
    }
    return 0;
}
