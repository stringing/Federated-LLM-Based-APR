#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
int A[10000];
using namespace std;
bool cmp(int a, int b) {
    int m1 , m2;
    m1 = a % 10 + a / 10;
    m2 = b % 10 + b / 10;
    if (m1 != m2){
        return m1 < m2;
    }
 return a < b;
}

int main() {
   int n;
   cin >> n;
   for (int i=0; i < n;i++){
       cin >> A[i];
   }
   sort (A ,A+n,cmp);
    for (int i=0; i < n;i++){
       cout << A[i] << " ";
   }
}
