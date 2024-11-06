#include<iostream>
using namespace std;
int main(){
    int a,b,n;
    int c;
    double ERROR=0.000001;
    cin >> n>> a>>b;
    c=n*a-600;
    int min=c/(b-a);
    int mini = (int)min;
    if(min!= mini){
       mini+=1;
    }
         
        cout << mini;
    
    
    return 0;
   
}
