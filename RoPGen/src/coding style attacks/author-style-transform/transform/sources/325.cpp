#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{
    freopen ("bigadd.in", "r", stdin);
    freopen ("bigadd.out", "w", stdout);
    long long s;
    cin >> s;
    s += 2018;
    cout << s << endl;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
