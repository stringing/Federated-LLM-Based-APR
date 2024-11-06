#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int num, number = 0, maxn = 0;
    string s, a;
    getline(cin, s);
    num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        number++;
        if (s[i] == ' ')
        {
            maxn = max(maxn, num);
            a = a.substr(num, number);
            number = 0;
            num = i + 1;
        }
    }
    cout << a;
    return 0;
}
