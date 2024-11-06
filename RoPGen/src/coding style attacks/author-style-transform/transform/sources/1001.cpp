#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> tree;
int b[10000];
int c[10000];

struct trenode
{
    int fa;
    int fa1;
    vector<int> ch;
};

int main()
{
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    vector<trenode> a;
    int t;
    int p = 0;
    cin>>t;
    int t1 = 0;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        for(int j = 0; j < n - 1; j++)
        {
            int x, y;
            cin>>x>>y;
            
            trenode tmp;
            tmp.fa = x;
            tmp.fa1++;
            tmp.ch.push_back(y);
            

            a.push_back(tmp);
        }
        for(int j = 0; j < t1; j++)
        {
            int t2 = a[j].fa1;
            if(t2 >= a[j + a[j].fa].fa1)
            {
                p++;
            }
        }
    }
    cout<<p<<endl;
    return 0;
}
