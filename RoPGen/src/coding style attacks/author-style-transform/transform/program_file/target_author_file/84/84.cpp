#include <iostream>
using namespace std;
int main() {
 int n, a, b, j, s, c = 1;
        cin >> n >> a >> b;
        j = n * a - 600;
        for (int i = 0;i <= c;i++){
               j = j + a - b;
                if (j == 0){
                        break;
                }
                c++;
        s++;
        }cout << s + 1;
    return 0;
}
