#include <iostream>
#include <algorithm>
using namespace std;
int sum(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main(){
    int n;
    string a[102];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }   
    sort (a, a + n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
