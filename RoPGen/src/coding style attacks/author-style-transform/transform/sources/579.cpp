#include<iostream>
using namespace std;
int main(){
    int a,b,n;
    int c;
    cin >> n>> a>>b;
    c=(n*a-600)/(b-a);
    if(c% 1 >= 0){
        
        cout << (int)c+1;
    }else{
        cout << c;
    }
    
    return 0;
}
