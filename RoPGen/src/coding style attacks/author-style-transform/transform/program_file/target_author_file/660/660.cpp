#include<iostream>
using namespace std;
int main(){
    int a,b,n;
    int c;
    double ERROR=0.000001;
    cin >> n>> a>>b;
    c=(n*a-600)/(b-a);
     if(c% 1==0){
        cout << c;
    }else {
         c+=1;
        cout << (int)c;
    }
    
    return 0;
   
}
