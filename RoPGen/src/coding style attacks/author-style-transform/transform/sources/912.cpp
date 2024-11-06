#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,c="";
    int max=0,sum=0,s;
    getline(cin,a);
    for (int i=0;i<a.size();i++) {
        if (a[i]==' '&&sum>max&&sum!=c.size()) {
            max=sum;
            sum=0;
            c=a.substr(i-max,max);
        }
        if (a[i]==' ') {
            sum=0;
        } else {
            sum++;
        }
    }
    s=a.size();
    if (sum>max) {
        cout <<a.substr(s-max,max)<<endl;
    } else {
        cout <<c<<endl;
    }
    return 0;
}
