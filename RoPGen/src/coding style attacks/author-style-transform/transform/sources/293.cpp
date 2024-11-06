#include <iostream>
using namespace std;   
int main() {
    int n,a,b;
    double i;
    cin >>n>>a>>b;
    i=(n*a-600)/(b-a)*1.0;
    if (int(i)==i)
    {
        cout <<i;
    }
    else
    {
        cout <<int(i)+1;
    }

    return 0;
}
