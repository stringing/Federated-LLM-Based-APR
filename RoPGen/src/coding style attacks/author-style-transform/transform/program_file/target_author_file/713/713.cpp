#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string t;
    getline(cin,t);
    int l = 0,r = 0,maxn = -8;
    for(int i = 0; i <= t.length() - 1; i++)
    {
        if(t[i] == ' ')
        {
            maxn = max(maxn,r);
            l = r - maxn;
            r = 0;
        }
        r++;
    }
    cout << t.substr(l,maxn) << " \n";
    return 0;
}
