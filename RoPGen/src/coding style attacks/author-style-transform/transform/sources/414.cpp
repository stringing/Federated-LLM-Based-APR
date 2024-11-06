#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int sum(string a) {
    int sum = 0;
    for (int i = 0; i < a.size();i++) {
        sum += (int)a[i];
    }
    return sum;
}
bool cmp(string x, string y){
    if(sum(x) != sum(y)){
        return sum(x) < sum(y);
    }
    return x < y;
}
int main(){
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++){
        cout >> a[i];
        }
    }
    return 0;
}
