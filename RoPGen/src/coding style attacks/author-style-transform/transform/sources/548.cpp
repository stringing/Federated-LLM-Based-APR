#include <iostream>
using namespace std;
int main(){
    int n, a, b,sum = 0, j = 0;
    cin >> n >> a >> b;
    for(int i = 1;n * b < 600 + n * a; i++){
        sum += n * b;
        if(sum >= 600 + n * a){
            j = i;
            break;
        }
    }
    cout << j << endl;
    return 0;
}
