#include <iostream>
using namespace std;   
int main() {
    double n,b,a,c;
    int d;
    cin >> n >> a >> b;
    c=n*a;
    if((n*a-600)%(b-a)==0){
        d=(n*a-600)/(b-a)+1;
    }else{
        d=(n*a-600)/(b-a);
    }
    cout << d << endl;
    return 0;
}

