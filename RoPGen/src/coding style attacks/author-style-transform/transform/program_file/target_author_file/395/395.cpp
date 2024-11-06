#include<iostream>
using namespace std;
void f(long long n){
    if(n == 12){
        return 
    }
    if(n == 6){
        return 
    }
    if(n == 3){
        return 
    }
    cout << n << ",";
    if(n %2 == 0){
        f(2*n);
    }else{
        f(3*n + 3);
    }
}
int main(){
    int n;
    cin >> n;

}
