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
        for (int j = 0 ; j < m ; j++)
        {
            for (int k = i ; k < i + j ; k++)
            {
                for (int p = j ; p < i + j ; p++)
                {
                    sum += a[k][p];
                }
            }
            if(sum > max)
            {
                max = sum;
            }
        }
    }
    cout << max << endl;
    return 0;
}
