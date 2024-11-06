#include <iostream>
using namespace std;

int main ()
{
    int n, f = 0, r = 0;
    string q[105];
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            string name;
            cin >> name;
            bool f = false;
            for (int i = f; i < r; i++)
            {
                if (name[0] == q[i][0])
                {
                    for (int j = r; j > i + 1; j--)
                    {
                        q[j] = q[j - 1];
                    }
                    q[i + 1] = name;
                    f = true;
                    break;
                }
            }
            if (!f)
            {
                q[r] = name;
            }
            r++;
        }
        else
        {
            if (f == r)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << q[f] << endl;
                f++;
            }
        }
    }
    return 0;
}
