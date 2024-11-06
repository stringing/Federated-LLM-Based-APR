#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
int A[10000];
using namespace std;
bool cmp(int a, int b) {
    int m1 = a;
    int s1 = 0;
    while (m1 != 0){
        s1 += m1 % 10;
        m1 /= 10;
    }
    int m2 = b;
    int s2 = 0;
    while (m2 != 0){
        s2 += m2 % 10;
        m2 /= 10;
    }
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
