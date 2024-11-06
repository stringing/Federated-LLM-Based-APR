#include <iostream>
#include <string>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    getchar();
    string f[1005] = {};
    string s;
    int x = 0;
    while (n > 0)
    {
        x = 0;
        for (int i = 0; i < 1005; i++)
        {
            f[i] = "";
        }
        getline (cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I')
            {
                s[i] += 32;
            }
            if (s[i] == '?')
            {
                s[i] = '!';
            }
            if (s[i] != ' ')
            {
                f[x] += s[i];
            }
            else
            {
                x++;
            }
        }
        for (int i = 0; i <= x; i++)
        {
            if (f[i] == "can" || f[i] == "could") && (f[i + 1] == "you")
            {
                cout << "I " << f[i] << " ";
                f[i + 1] = "0";
            }
            else if (f[i] == "I" || f[i] == "me")
            {
                cout << "you ";
            }
            else if (f[i] != "0")
            {
                cout << f[i] << " ";
            }
        }
        cout << endl;
        n--;
    }
    cout << endl;
    return 0;
}
