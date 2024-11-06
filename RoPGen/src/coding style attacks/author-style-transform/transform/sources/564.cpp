#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(queue<string> a, queue<string> b) {
    return a < b;
}

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            string s;
            cin >> s;
            q.push(s);
        }
        if(op == 2) {
            sort(q, q + q.size(), cmp);
            cout << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}
