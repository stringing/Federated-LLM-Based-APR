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
            c=a.substr(i-max-1,max);
            s=i;
            sum=0;
        }
        sum++;
    }
    if (sum>max) {
        cout <<a.substr(s-max-1,max)<<endl;
    } else {
        cout <<c<<endl;
    }
    return 0;
}
