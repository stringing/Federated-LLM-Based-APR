#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int pow(int n){
    return n*n;
}
int main() { 
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=0;;i++){
        for(int j=0;;j++){
            for(int k=0;;k++){
                double x=sqrt(n-pow(i)-pow(j)-pow(k));
                if(x-int(x)==0){
                    cout<<i<<" "<<j<<" "<<k<<" "<<x<<endl;
                    break;
                }
            }
        }    
    }
    return 0;
}
