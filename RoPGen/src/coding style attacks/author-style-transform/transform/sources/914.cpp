#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,c="";
    int max=0,sum=0;
    getline(cin,a);
    for (int i=0;i<a.size();i++) {
        if (a[i]==' '&&sum>max&&sum!=c.size()) {
            max=sum;
            c=a.substr(i-max,max);
            sum=0;
        }
        sum++;
    }
    cout <<c<<endl;
    return 0;
}
