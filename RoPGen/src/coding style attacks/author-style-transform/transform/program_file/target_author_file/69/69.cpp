#include <iostream>
using namespace std;
int main() {
    int n,a,b,c;
    cin>>n>>a>>b;
    c = n * a;
    cout<<(c - 100) / (b - a)<<endl;   
    return 0;
}
