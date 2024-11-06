#include<bits/stdc++.h>
using namespace std;
vector<int> tree[1005];
int main() {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int x, y;
        for(int i = 1; i < n; i++) {
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            bool flag = true;
            for(int j = 0; j < tree[i].size(); j++) {
               if(tree[tree[i][j]].size() > tree[i].size()){
                   flag = false;
                   break;
               }
            }
            if(flag){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
