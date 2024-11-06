#include<iostream>
using namespace std;
void f(long long n){
    if(n == 12){
        cout << "12" << "," << "6" << "," << "3" << "," <<"12";
    }
    if(n == 6){
        cout <<  "6" <<"," << "12" <<","<< "6" <<","<< "6";
    }
    if(n == 3){
        cout <<"3" <<"," <<"," << "12"<<"," << "6"<<"," << "3";
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
