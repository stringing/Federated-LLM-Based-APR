#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a[10000]

string cmp (string x,string y){
    return x.size() < b.size()
        || x.size() == b.size() && x.size() != b.size();
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(int i = 0;i<n;i++){
        cout << a[i] << endl;
    }
    return 0;
}
