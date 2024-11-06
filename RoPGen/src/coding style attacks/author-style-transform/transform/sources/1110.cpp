#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 0, maxn = 0, start = 0;
    string a, b;
    getline(cin, a);
    a += ' ';
    for (int i = 0; i < a.size(); i++)
    {
        num++;
        if (a[i] == ' ')
        {
            start = i + 1;
            if (num > maxn)
            {
                maxn = num;
                b = b.substr(start, num);
                num = 0;
            }
        }
    }
    cout << b;
    return 0;
}




