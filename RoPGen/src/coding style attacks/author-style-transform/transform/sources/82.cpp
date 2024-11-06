#include <bits/stdc++.h>
using namespace std;
struct gem {
    int r, t, p;
}g;
vector <gem> gems;
double sum1[1005], num[1005];
int n, p, k, t;
string s;
long long sum;
bool cmp (gem x, gem y)
{
    if (sum1[x.r] / num[x.r] != sum1 [y.r] / num [y.r]) 
    {
        return sum1[x.r] / num [x.r] < sum1[y.r] / num [y.r];
    }
    if (x.p != y.p) 
    {
        return x.p > y.p;
    }
    return x.t < y.t;
}
int main ()
{
    cin >> n;
    while (n --) 
    {
        cin >> g.r >> g.p >> k;
        for (int i = 1; i <= k; i++) 
        {
           g.t = t++;
           sum1[g.r] += g.p;
           num[g.r] += 1.0;
           gems.push_back(g);
        } 
    }
    sort (gems.begin(), gems.end(), cmp);
    for (int i = 0; i < gems.size(); i++)
    {
        sum += abs (gems[i].t - (i + 1));
    } 
    cout << sum << endl;
    return 0;
}
