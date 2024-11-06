#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b, num;
struct data {
    int left, right;
} m[1005];

void process(vector<int> x, vector<int> y) {
    if (x.size() == 0) return;
    int root = x[x.size() - 1];
    if (x.size() == 1) {
        m[root].left = m[root].right = 0;
        return;
    }
    if (x.size() == 2) { 
        if (x[0] == y[0]) { 
            m[y[0]].left = m[y[0]].right = m[x[0]].right = 0;
            m[y[1]].left = x[0];
        } else { 
            m[y[0]].left = m[y[0]].right = m[x[0]].left = 0;
            m[y[1]].right = x[0];
        }
        return;
    }
    if (x.size() == 3) { 
        if (y[1] == root) { 
            m[root].left = y[0];
            m[root].right = y[2];
            m[y[0]].left = m[y[0]].right = m[y[2]].left = m[y[2]].right = 0;
        } else if (y[2] == root) { 
            m[root].left = y[1];
            m[root].right = 0;
            y.pop_back();
            x.pop_back(); 
            process(x, y);
        } else { 
            x.pop_back();
            y.erase(y.begin()); 
            m[root].left = 0;
            m[root].right = x[1];
            process(x, y);
        }
        return;
    } else { 
        int pos;
        for (int i = 0; i < y.size(); i++) {
            if (y[i] == root) {pos = i; break;}
        }
        vector<int> lx, rx, ly, ry; 
        for (int i = 0; i < pos; i++) {
            lx.push_back(x[i]);
            ly.push_back(y[i]);
        }
        for (int i = pos + 1; i < x.size(); i++) {
            rx.push_back(x[i]);
            ry.push_back(y[i]);
        }
        m[root].left = lx.size() ? lx[lx.size() - 1] : 0;
        m[root].right = rx.size() ? rx[rx.size() - 1] : 0;
        process(lx, ly);
        process(rx, ry);
        return;
    }
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
        num.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    sort(num.begin(), num.end()); 
    process(a, b);
    for (int i = 0; i < num.size(); i++) {
        cout << m[num[i]].left << " " << m[num[i]].right << endl;
    }
    return 0;
}
