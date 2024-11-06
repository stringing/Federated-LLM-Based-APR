#include<iostream>
#include<math.h>
using namespace std;
int main(){
    for(int a = 0;a * a <= n;a++){
        for(int b = 0;b * b + a * a <= n;b++){
            for(int c = 0;c * c + b*b+a* a <= n;c++){
                int d = sqrt(n - a*a - b*b - c*c);
                if(d == n){
                    cout << a<<" " << b<< " " << c << endl;
                    return 0;
                }
            }
        }
    }   
}
