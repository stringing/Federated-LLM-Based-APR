#include<iostream>
using namespace std;
void f(long long n){
    if(n == 12){
        cout << "12" << ", " << "6" << ", " << "3" << ", " <<"12";
        return;
    }
    if(n == 6){
        cout <<  "6" <<", " << "12" <<", "<< "6" <<", "<< "6";
        return ;
    }
    if(n == 3){
        cout <<"3" <<", " << "12"<<", " << "6"<<", " << "3";
        return ;
    }
    cout << n << ",";
    if(n %2 == 0){
        f(n/2);
    }else{
        f(3*n + 3);
    }
}
int main(){
    int n;
    cin >> n;
    f(n);
}
