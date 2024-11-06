#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005];
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
        }
    }
    int max = -1000;
    for (int i = 0 ; i < n ; i++)
    {
        int sum = 0;
        for (int j = 0 ; j < n ; j++)
        {
            for (int k = 0 ; k < m ; k++)
            {
                for (int p = 0 ; p < m ; p++)
                {
                    for (int g = i ; g <= j ; g++)
                    {
                        for (int q = k ; q <= p ; q++)
                        {
                            sum += a[g][q];
                        }
                    }
                    if(sum > max)
                    {
                        max = sum;
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}
