#include <iostream>
using namespace std;
int main() {
    int n,a ,b;
    cin >> n >> a >> b;
    int temp = n * a -600;
    double min = temp / (b-a);
    int min_int = int(min);
    if(min_int != min) {
        min_int++;
    }
    cout << min_int;
    return 0;
}
