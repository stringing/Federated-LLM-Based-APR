#include <iostream>
using namespace std;
int main (){
    int n, a, b, min = 0;
    cin >> n >> a >> b;
    while (a * min < b * n + b * min){
        min++;
        if (a * min + 600 >= b * n + b * min){
            break;
        }
    }
    cout << min;
    return 0;
}
