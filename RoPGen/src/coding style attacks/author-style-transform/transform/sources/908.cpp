#include <iostream>
#include <cstring>
using namespace std;
string s;
int t2t(int a1, int a2)
{
    int cnt = 1, sum = 0;
    for (int k = a2; k >= a1; k--)
    {
        sum += cnt * s[k];
        cnt *= 2;
    }
    return sum;
}
string t2s(int x)
{
    string abc = "";
    while (x > 0)
    {
        abc = (char)(x % 10 + '0') + abc;
        x /= 10;
    }
    return abc;
}
int main()
{
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    cin >> s;
    string ans = "";
    bool flag = 1;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s.length() % 8 != 0)
        {
            cout << "Error";
            flag = 0;
            break;
        }
        for (int j = 0; j <= s.length() - 1; j++)
        {
            if (s[j] != '1' && s[j] != '0')
            {
                cout << "Error";
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        if (s[i] == '1')
        {
            if (s[i + 1] == '1' && s[i + 2] == '1')
            {
                ans = ans + ' ';
                i += 7;
            }
            else if (s[i + 1] == '0' && s[i + 2] == '1')
            {
                if (t2t(i + 3, i + 7) <= 25)
                {
                    ans = ans + (char)('A' + t2t(i + 3, i + 7));
                    i += 7;
                }
                else
                {
                    cout << "Error";
                    flag = 0;
                    break;
                }
            }
            else
            {
                cout << "Error";
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        if (s[i] == '0')
        {
            if (s[i + 8] == '0')
            {
                ans = ans + t2s(t2t(i + 1, i + 7) / 2 + t2t(i + 9, i + 15) / 2);
                i += 15;
            }
            else
            {
                cout << "Error";
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    if (flag == 1)
    {
        cout << ans;
    }
    return 0;
}
